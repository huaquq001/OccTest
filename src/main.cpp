#include "MyQtWidgetsApplication.h" 
#include <QApplication>
int main(int argc, char* argv[]) 
{
	QApplication a(argc, argv);
	MyQtWidgetsApplication w; w.show();
	return a.exec();
}