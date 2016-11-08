#include "elitelogconvert.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	EliteLogConvert w;
	w.show();

	return a.exec();
}
