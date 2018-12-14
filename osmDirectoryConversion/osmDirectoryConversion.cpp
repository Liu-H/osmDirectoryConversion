#include "osmDirectoryConversion.h"
#include <QFileDialog>
#include <QDebug>

osmDirectoryConversion::osmDirectoryConversion(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	files = Q_NULLPTR;
	connect(ui.inFileDialogBtn, &QPushButton::clicked, this, &osmDirectoryConversion::on_openFileDir);
	connect(ui.outFileDialogBtn, &QPushButton::clicked, this, &osmDirectoryConversion::on_openFileDir);
	connect(ui.inDirInputEdit, &QLineEdit::textChanged, this, &osmDirectoryConversion::on_dirChange);
	connect(ui.outDirInputEdit, &QLineEdit::textChanged, this, &osmDirectoryConversion::on_dirChange);
	connect(ui.transformBtn, &QPushButton::clicked, this, &osmDirectoryConversion::on_transfrom);
	connect(ui.updateBtn, &QPushButton::clicked, this, &osmDirectoryConversion::on_updata);
}

void osmDirectoryConversion::on_openFileDir()
{
	QString dir = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("打开文件"),
	                                                QApplication::applicationDirPath(),
	                                                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);


	QObject* obj = QObject::sender();


	if (dir.isEmpty())
	{
		return;
	}

	if (obj->objectName() == "inFileDialogBtn")
	{
		ui.inDirInputEdit->setText(dir);
	}
	else
	{
		ui.outDirInputEdit->setText(dir);
	}
}

void osmDirectoryConversion::on_dirChange(QString path)
{
	QObject* obj = QObject::sender();
	QString str = obj->objectName();
	if (str == "inDirInputEdit")
	{
		showInFiles(path);
	}
	else
	{
		showOutFiles(path);
	}
}

void osmDirectoryConversion::on_transfrom()
{
	fileTransfrom();
}

void osmDirectoryConversion::on_updata()
{
	showInFiles(ui.inDirInputEdit->text());
	showOutFiles(ui.outDirInputEdit->text());
}

FileItem* osmDirectoryConversion::findFiles(QString path, QObject* parentDir, FileItem* pDir)
{
	QDir dir(path);
	bool ok;
	int dirValue;

	if (!dir.exists())
	{
		return Q_NULLPTR;
	}
	FileItem* item = new FileItem(parentDir, pDir);
	QString dirName = dir.dirName();
	item->setName(dirName);
	item->setPath(path);
	//判断是否问坐标
	dirValue = dirName.toInt(&ok);
	if (ok)
	{
		if (pDir != Q_NULLPTR)
		{
			if (pDir->getZ() == 0)
			{
				item->setZ(dirValue);
			}
			else
			{
				item->setZ(pDir->getZ());
				if (pDir->getX() == 0)
				{
					item->setX(dirValue);
				}
				// {
				// 	item->setX(pDir->getX());
				// }
			}
		}
	}


	QFileInfoList fileInfos = dir.entryInfoList(QDir::Files);
	for (int i = 0; i < fileInfos.count(); ++i)
	{
		QString name = fileInfos.at(i).fileName();
		item->addFile(name);
	}

	QFileInfoList dirInfos = dir.entryInfoList(QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

	for (int i = 0; i < dirInfos.count(); ++i)
	{
		QFileInfo fileInfo = dirInfos.at(i);
		QString fileName = fileInfo.fileName();
		QString filepath = fileInfo.absoluteFilePath();
		item->addDir(fileName, findFiles(filepath, item, item));
	}

	return item;
}

void osmDirectoryConversion::showFiles(QString path, QTreeWidgetItem* item)
{
	QDir dir(path);
	if (!dir.exists())
	{
		return;
	}

	QFileInfoList dirInfos = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

	for (int i = 0; i < dirInfos.count(); ++i)
	{
		QFileInfo fileInfo = dirInfos.at(i);
		QString fileName = fileInfo.fileName();
		QString filepath = fileInfo.absoluteFilePath();
		item->setText(i, fileName);
		if (fileInfo.isDir())
		{
			QTreeWidgetItem* childitem = new QTreeWidgetItem(item);
			showFiles(filepath, childitem);
			item->addChild(childitem);
		}
	}
}

void osmDirectoryConversion::showOutFiles(QString path)
{
	QDir dir(path);
	if (!dir.exists())
	{
		return;
	}
}

void osmDirectoryConversion::showInFiles(QString path)
{
	QDir dir(path);
	ui.infileTree->clear();
	if (files != Q_NULLPTR)
	{
		files->deleteLater();
		files = Q_NULLPTR;
	}
	if (!dir.exists())
	{
		return;
	}
	files = findFiles(path, this, Q_NULLPTR);

	QFileInfoList dirInfos = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDot | QDir::NoDotDot);

	for (int i = 0; i < dirInfos.count(); ++i)
	{
		QFileInfo fileInfo = dirInfos.at(i);
		QString fileName = fileInfo.fileName();
		QString filepath = fileInfo.absoluteFilePath();
		QTreeWidgetItem* item = new QTreeWidgetItem(ui.infileTree);
		item->setText(0, fileName);
		if (fileInfo.isDir())
		{
			QTreeWidgetItem* childitem = new QTreeWidgetItem(item);
			showFiles(filepath, childitem);
		}
		ui.infileTree->addTopLevelItem(item);
	}
}

void osmDirectoryConversion::fileTransfrom()
{
	saveAsFile(files);
}

void osmDirectoryConversion::saveAsFile(FileItem* pDir)
{
	QString outDir = ui.outDirInputEdit->text();
	QString prefix = "osm_100-l-";

	QDir dir(outDir);
	if (!dir.exists())
	{
		return;
	}
	if (files == Q_NULLPTR)
	{
		return;
	}
	int z = pDir->getZ();
	int x = pDir->getX();
	if (z != 0 && x != 0)
	{
		QString dirPath = pDir->getPath() + "/";
		for (int i = 0; i < pDir->getFiles().size(); ++i)
		{
			QString fileName, infilePath;
			fileName = pDir->getFiles().at(i);
			infilePath = dirPath + fileName;
			//文件读取保存
			QFile infile(infilePath);
			if (infile.open(QIODevice::ReadOnly))
			{
				QByteArray data = infile.readAll();
				infile.close();
				fileName.replace(".png", ".jpg");
				QString outFiles = outDir + "/" + QString("osm_100-l-1-%1-%2-%3").arg(z).arg(x).arg(fileName);
				QFile outfile(outFiles);
				if (outfile.open(QIODevice::ReadWrite))
				{
					outfile.write(data);
					outfile.close();
				}
			}
		}
	}


	QList<FileItem *> values = pDir->getDirs().values();

	for (int i = 0; i < values.size(); ++i)
	{
		saveAsFile(values.at(i));
	}
}


