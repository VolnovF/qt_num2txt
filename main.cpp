#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QObject::connect(w.convert_button, &QPushButton::clicked, &w, &Widget::convertToTxt);
    w.show();
    return a.exec();
}
