
#include "Space_Invaders.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Space_Invaders w;
	w.show();
	return a.exec();
}
