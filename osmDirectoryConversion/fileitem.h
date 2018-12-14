#pragma once

#include <QObject>
#include <QMap>
class FileItem : public QObject
{
	Q_OBJECT

public:
	FileItem(QObject *parent,FileItem *pDir);
	~FileItem();

	QMap<QString, FileItem*> getDirs() const;
	void addDir(QString key, FileItem *value);


	QStringList getFiles() const;
	void addFile(QString fileName);


	int getZ() const;
	void setZ(int value);

	int getX() const;
	void setX(int value);

	QString getPath() const;
	void setPath(const QString &value);

	QString getName() const;
	void setName(const QString &value);

private:
	 QMap<QString,FileItem *> dirs;
	 QStringList files;
	 int z;
	 int x;
	 QString path;
	 QString name;
	 FileItem *parentDir;


public:
	FileItem* GetParentDir() const;
	void SetParentDir(FileItem* const ParentDir);
};
