#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    /*auto conv = NumToTxt("0");
    QString result = conv.toText();
    conv.clear();*/
    w.show();
    return a.exec();
}
