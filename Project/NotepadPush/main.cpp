#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(800,500);
    w.setWindowTitle("Persistence efforts");
    w.setWindowIcon(QIcon(":/11.jpg"));
    w.show();

    return a.exec();
}
