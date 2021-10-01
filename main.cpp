#include "mainwindow.h"
#include "graphick.h"
#include <QApplication>

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);
   MainWindow window;
   Graphick mwindow;
   window.setGraf(mwindow);
 mwindow.show();
   window.show();
    return a.exec();
}
