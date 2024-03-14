#include "numtotxt.h"

NumToTxt::NumToTxt()
{}

NumToTxt::NumToTxt(QString number)
{
    setNumber(number);
}

bool NumToTxt::setNumber(QString number)
{
    QChar letter;
    size = 0;
    for (int i = number.size() - 1; i > -1; --i)
    {
        letter = number [i];
        if (i == 0 && letter == '-')
        {
            isNegativeNumber = true;
        }
        else if (letter.isDigit() && size < maxSize)
        {
            digits [size] = letter.digitValue();
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
        digits [i] = 0;
    }
    size = 0;
    isNegativeNumber = false;
}

uint NumToTxt::orderInSector(uint index)
{
    return index % 3;
}

uint NumToTxt::getIndex(uint sector, uint order)
{
    return sector * 3 + order;
}

uint NumToTxt::getSector(uint index)
{
    return index / 3;
}

QString NumToTxt::toText()
{
    if (!size)
    {
        return "";
    }

    const char** digitsUnnamedMask [maxSize] {nullptr};
    for (uint i = 0; i < size; ++i)
    {
        if (orderInSector(i) == 1 && digits [i] == 1)
        {
            digitsUnnamedMask [i] = nullptr;
            digitsUnnamedMask [i-1] = numerals [3];
        }
        else if (i == 3)
        {
            if (digits [i] == 1 || digits [i] == 2)
            {
                digitsUnnamedMask [i] = femaleOneAndTwo;
            }
        }
        else
        {
            digitsUnnamedMask [i] = numerals [orderInSector(i)];
        }
    }

    sectorName names [(maxSize-1)/3] {nullptr};
    uint countNames {(size/3)+1};
    uint variantOfEnd {0};
    for (uint i = 0; i < countNames; ++i)
    {
        names[i].begin = sectorNameBegin [i];
        if(size > getIndex(i,1) && digits [getIndex(i,1)] == 1)
        {
            names[i].end = sectorNameEnd [i] [2];
        }
        else
        {
            variantOfEnd += ( digits [getIndex(i,0)] != 1 ? 1 : 0);
            variantOfEnd += ( digits [getIndex(i,0)] > 4 ? 1 : 0);
            variantOfEnd += ( digits [getIndex(i,0)] == 0 ? 1 : 0);
            names[i].end = sectorNameEnd [i] [variantOfEnd];
            variantOfEnd = 0;
        }
    }

    QString text;
    QTextStream stream {&text};
    if (isNegativeNumber)
    {
        stream << "минус ";
    }
    bool sectorIsEmpty {true};
    for (int i = size - 1; i > -1; --i)
    {
        if (digitsUnnamedMask [i] && (digits [i] != 0 || i == 0))
        {
            stream << digitsUnnamedMask [i] [digits [i]] << ' ';
            sectorIsEmpty = false;
        }
        if (orderInSector(i) == 0)
        {
            if (!sectorIsEmpty)
            {
                stream << names [getSector(i)].begin;
                stream << names [getSector(i)].end << ' ';
                sectorIsEmpty = true;
            }
        }
    }

    return text;
}

uint NumToTxt::getSize() const
{
    return size;
}

