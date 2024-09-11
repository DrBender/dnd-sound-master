#include <QApplication>
#include <iostream>
#include "src/MainWindow.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setOrganizationName("DrBender");
    QCoreApplication::setApplicationName("DnD Sound Master");

    cout << "Dnd Sound Master" << endl;

    MainWindow w;
    w.show();

    return app.exec();

}
