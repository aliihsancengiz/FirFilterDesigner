#include "filterdesigner.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FilterDesigner w;
    w.show();
    return a.exec();
}
