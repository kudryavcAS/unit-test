//Алексей Кудрявцев, 6-я группа

#include <QtTest>
#include "number.h"
// add necessary includes here

class Test_Number : public QObject
{
    Q_OBJECT

public:
    Test_Number();
    ~Test_Number();

private slots:
    void test_NotLargeSumCub();
    void test_SearchPrime();
    void test_FirstNoNull();
    void test_DubblLarg();
};

Test_Number::Test_Number() {}

Test_Number::~Test_Number() {}

void Test_Number::test_NotLargeSumCub() {
    number num;
    QString buffer;
    QTextStream out(&buffer);

    num.NotLargSumCub(out, 3);
    QCOMPARE(buffer, QString("Числа, меньше Х, равные сумме кубов цифр:\n1"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.NotLargSumCub(out, 154);
    QCOMPARE(buffer, QString("Числа, меньше Х, равные сумме кубов цифр:\n1\n153"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.NotLargSumCub(out, 400);
    QCOMPARE(buffer, QString("Числа, меньше Х, равные сумме кубов цифр:\n1\n153\n370\n371"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.NotLargSumCub(out, 900);
    QCOMPARE(buffer, QString("Числа, меньше Х, равные сумме кубов цифр:\n1\n153\n370\n371\n407"));

}
void Test_Number::test_SearchPrime(){
    number num;
    QString buffer;
    QTextStream out(&buffer);

    num.SearchPrimeSumQuad(out, 4, 1);
    QCOMPARE(buffer, QString("X*X - Y*Y = 3*5, где 3 и 5 - простые числа."));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.SearchPrimeSumQuad(out, 25, 24);
    QCOMPARE(buffer, QString("X*X - Y*Y = 7*7, где 7 и 7 - простые числа."));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.SearchPrimeSumQuad(out, 5, 4);
    QCOMPARE(buffer, QString("X*X - Y*Y = 3*3, где 3 и 3 - простые числа."));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.SearchPrimeSumQuad(out, 3, 1);
    QCOMPARE(buffer, QString("Таких простых чисел нет"));
}
void Test_Number::test_FirstNoNull(){
    number num;
    QString buffer;
    QTextStream out(&buffer);

    num.FirstNoNullFactRight(out, 6);
    QCOMPARE(buffer, QString("Первая ненулевая цифра числа Х!:\n2"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.FirstNoNullFactRight(out, 13);
    QCOMPARE(buffer, QString("Первая ненулевая цифра числа Х!:\n8"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.FirstNoNullFactRight(out, 100);
    QCOMPARE(buffer, QString("Первая ненулевая цифра числа Х!:\n4"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.FirstNoNullFactRight(out, 2000000);
    QCOMPARE(buffer, QString("Первая ненулевая цифра числа Х!:\n8"));

}
void Test_Number::test_DubblLarg(){
    number num;
    QString buffer;
    QTextStream out(&buffer);

    num.DublLarg(out, 13);
    QCOMPARE(buffer, QString("133"));

    buffer.clear();
    out.seek(0);
    out.setString(&buffer, QIODevice::WriteOnly);

    num.DublLarg(out, 34545);
    QCOMPARE(buffer, QString("3455455"));

}

QTEST_APPLESS_MAIN(Test_Number)

#include "tst_test_number.moc"
