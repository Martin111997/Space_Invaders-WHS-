#include "Space_Invaders.h"
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Space_Invaders w;
	w.show();
	return a.exec();
}
