#ifndef NUMTOTXT_H
#define NUMTOTXT_H

#include <QString>

class NumToTxt
{
private:
    ;
private:
    static const size_t maxSize {9};
    size_t digits [maxSize];
    size_t size {0};
    bool isNegativeNumber {false};
public:
    NumToTxt();
    NumToTxt(QString number);

    bool setNumber(QString number);
    void clear();
    QString toText();
    size_t getSize() const;
private:
    ;
};

#endif // NUMTOTXT_H
