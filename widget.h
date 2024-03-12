#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "numtotxt.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    QVBoxLayout *layout;
    QPushButton *convert_button;
    QHBoxLayout *button_layout;
    QLineEdit *input_number;
    QTextEdit *output_text;
};
#endif // WIDGET_H
