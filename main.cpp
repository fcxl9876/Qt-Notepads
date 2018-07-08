#include "notepads.h"
#include "newpage.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Notepads w;
    w.show();
    return a.exec();
}
