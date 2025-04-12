#include "fly_bird.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fly_bird w;
    w.show();
    return a.exec();
}
