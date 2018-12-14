#pragma once

#include <QtWidgets/QWidget>
#include "ui_osmDirectoryConversion.h"
#include "fileitem.h"

class osmDirectoryConversion : public QWidget
{
	Q_OBJECT

public:
	osmDirectoryConversion(QWidget *parent = Q_NULLPTR);

private:
	Ui::osmDirectoryConversionClass ui;
	FileItem *files;
public slots:
	void on_openFileDir();
	void on_dirChange(QString path);
	void on_transfrom();
	void on_updata();

private:
	FileItem *findFiles(QString path, QObject *parentDir, FileItem* pDir);
	void showFiles(QString path,QTreeWidgetItem *item);
	void showOutFiles(QString path);
	void showInFiles(QString path);
	void fileTransfrom();

	void  saveAsFile(FileItem* pDir);
};
