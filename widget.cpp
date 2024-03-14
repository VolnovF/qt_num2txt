#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    converter = new NumToTxt;

    input_number = new QLineEdit;
    input_number->setMaxLength(10);
    input_number->setAlignment(Qt::AlignHCenter);
    input_number->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    convert_button = new QPushButton("Пропись");
    convert_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    output_text = new QTextEdit();
    output_text->setReadOnly(true);
    //output_text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    //output_text->setAlignment(Qt::AlignHCenter);

    input_layout = new QHBoxLayout;
    input_layout->addWidget(input_number);

    button_layout = new QHBoxLayout;
    button_layout->addWidget(convert_button);

    layout = new QVBoxLayout;
    layout->addLayout(input_layout);
    layout->addLayout(button_layout);
    layout->addWidget(output_text);

    setLayout(layout);
    ;
    setMinimumWidth(400);
    setMinimumHeight(170);
}

Widget::~Widget()
{
    delete converter;
}

void Widget::convertToTxt()
{
    converter->setNumber(input_number->text());
    output_text->setText(converter->toText());
}

