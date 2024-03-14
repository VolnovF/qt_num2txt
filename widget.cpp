#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    input_number = new QLineEdit;
    input_number->setAlignment(Qt::AlignHCenter);

    convert_button = new QPushButton("Пропись");
    convert_button->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    output_text = new QTextEdit();
    output_text->setReadOnly(true);
    //output_text->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    //output_text->setAlignment(Qt::AlignHCenter);

    button_layout = new QHBoxLayout;
    button_layout->addWidget(convert_button);

    layout = new QVBoxLayout;
    layout->addWidget(input_number);
    layout->addLayout(button_layout);
    layout->addWidget(output_text);

    setLayout(layout);
    setMinimumWidth(400);
    setMaximumHeight(150);


    //auto ntt = NumToTxt("f");
    //output_text->setText( QString::number(ntt.getSize()) );
}

Widget::~Widget()
{
}

