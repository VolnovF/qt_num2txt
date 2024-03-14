#ifndef NUMTOTXT_H
#define NUMTOTXT_H

#include <QString>
#include <QTextStream>

//#include "words.h"

//namespace w = words;

class NumToTxt
{
private:
    struct sectorName
    {
        const char* begin {nullptr};
        const char* end {nullptr};
    };
    static constexpr uint maxSize {9};
    uint digits [maxSize] {0}; // числа хранятся в порядке возрастания порядка (единицы -> десятки -> и т.д.)
    uint size {0};
    bool isNegativeNumber {false};
public:
    NumToTxt();
    NumToTxt(QString number);
    uint getSize() const;
    bool setNumber(QString number);
    QString toText();
    void clear();
private:
    uint orderInSector(uint index);
    uint getIndex(uint sector, uint order);
    uint getSector(uint index);
    static const inline char* numerals [4] [10]
    {
        {
            "ноль"  ,
            "один"  ,
            "два"   ,
            "три"   ,
            "четыре",
            "пять"  ,
            "шесть" ,
            "семь"  ,
            "восемь",
            "девять"
        },
        {
            "ноль"       ,
            "десять"     ,
            "двадцать"   ,
            "тридцать"   ,
            "сорок"      ,
            "пятдесят"   ,
            "шестьдесят" ,
            "семьдесят"  ,
            "восемьдесят",
            "девяносто"
        },
        {
            "ноль"     ,
            "сто"      ,
            "двести"   ,
            "тристо"   ,
            "четыресто",
            "пятьсот"  ,
            "шестьсот" ,
            "семьсот"  ,
            "восемьсот",
            "девятьсот"
        },
        {
            "десять"        ,
            "одиннадцать"   ,
            "двенадцать"    ,
            "тринадцать"    ,
            "четырнадцать"  ,
            "пятнадцать"    ,
            "шестнадцать"   ,
            "семнадцать"    ,
            "восемнадцать"  ,
            "девятнадцать"
        }
    };
    static const inline char* femaleOneAndTwo [3]
    {
        "ноль",
        "одна",
        "две"
    };
    static const inline char* sectorNameBegin [3]
    {
        "рубл",
        "тысяч",
        "миллион"
    };
    static const inline char* sectorNameEnd [3] [3]
    {
        {
            "ь",
            "я",
            "ей"
        },
        {
            "а",
            "и",
            ""
        },
        {
            "",
            "а",
            "ов"
        },
    };
};

#endif // NUMTOTXT_H
