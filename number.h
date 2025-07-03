#ifndef NUMBER_H
#define NUMBER_H
#include <QTextStream>

class number
{
public:
    number();

    void NotLargSumCub(QTextStream& out, int )const;
    void SearchPrimeSumQuad(QTextStream&  out, int, int) const;
    void FirstNoNullFactRight(QTextStream& out, int) const;
    void DublLarg(QTextStream& out, int) const;
};

#endif // NUMBER_H
