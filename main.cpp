#include <QtGui/QApplication>
#include "restarteur.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Restarteur w;
    w.show();
    return a.exec();
}
