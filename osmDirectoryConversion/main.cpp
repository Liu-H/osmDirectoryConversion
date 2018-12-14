#include "osmDirectoryConversion.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	osmDirectoryConversion w;
	w.show();
	return a.exec();
}
