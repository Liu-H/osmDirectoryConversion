#include "fileitem.h"
#include <QFileDialog>
#include <QApplication>


FileItem::FileItem(QObject* parent, FileItem* pDir) : QObject(parent)
{
	parentDir = pDir;
	this->x = 0;
	this->z = 0;
}

FileItem::~FileItem()
{
}

QMap<QString, FileItem*> FileItem::getDirs() const
{
	return dirs;
}

void FileItem::addDir(QString key, FileItem* value)
{
	this->dirs.insert(key, value);
}


QStringList FileItem::getFiles() const
{
	return files;
}

void FileItem::addFile(QString fileName)
{
	files.append(fileName);
}


int FileItem::getZ() const
{
	return z;
}

void FileItem::setZ(int value)
{
	z = value;
}

int FileItem::getX() const
{
	return x;
}

void FileItem::setX(int value)
{
	x = value;
}

QString FileItem::getPath() const
{
	return path;
}

void FileItem::setPath(const QString& value)
{
	path = value;
}

QString FileItem::getName() const
{
	return name;
}

void FileItem::setName(const QString& value)
{
	name = value;
}

FileItem* FileItem::GetParentDir() const
{
	return parentDir;
}

void FileItem::SetParentDir(FileItem* const ParentDir)
{
	parentDir = ParentDir;
}
