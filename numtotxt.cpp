#include "numtotxt.h"

NumToTxt::NumToTxt()
{}

NumToTxt::NumToTxt(QString number)
{
    setNumber(number);
}

bool NumToTxt::setNumber(QString number)
{
    for (auto iter = number.constBegin(); iter != number.constEnd(); iter++)
    {
        if (iter == number.begin() && *iter == '-')
        {
            isNegativeNumber = true;
        }
        else if (iter->isDigit() && size < maxSize)
        {
            digits[size] = iter->digitValue();
            size++;
        }
        else
        {
            clear();
            return false;
        }
    }
    return true;
}

void NumToTxt::clear()
{
    for (size_t i = 0; i < maxSize; ++i)
    {
        digits[i] = 0;
    }
    size = 0;
    isNegativeNumber = false;
}

QString NumToTxt::toText()
{

}

size_t NumToTxt::getSize() const
{
    return size;
}

