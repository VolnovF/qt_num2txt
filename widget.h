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

    NumToTxt *converter;
    QVBoxLayout *layout;
    QPushButton *convert_button;
    QHBoxLayout *button_layout;
    QLineEdit *input_number;
    QHBoxLayout *input_layout;
    QTextEdit *output_text;
public slots:
    void convertToTxt();
};
#endif // WIDGET_H
