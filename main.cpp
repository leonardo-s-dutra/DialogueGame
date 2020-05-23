#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile styleSheetFile(":/styles/styleSheet.css");
    styleSheetFile.open(QFile::ReadOnly);

    a.setStyleSheet(styleSheetFile.readAll());

    MainWindow w;

    w.show();
    return a.exec();
}
