#include "metro.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Metro w;
    w.show();

    return a.exec();
}
