Смотреть в режиме code
Данный проект представляет собой проект unit-тестирования класса Number, то есть его 4-х методов (см. SP_1_QT)
    void NotLargSumCub(QTextStream& out, int )const;
    void SearchPrimeSumQuad(QTextStream&  out, int, int) const;
    void FirstNoNullFactRight(QTextStream& out, int) const;
    void DublLarg(QTextStream& out, int) const;
Класс test_number имеет соответсвенно 4 приватных слота, каждый из которых тестирует соответствующий метод класса number:
    void test_NotLargeSumCub();
    void test_SearchPrime();
    void test_FirstNoNull();
    void test_DubblLarg();
На примере   void test_NotLargeSumCub():
void Test_Number::test_NotLargeSumCub() {
    number num;
    QString buffer;
    QTextStream out(&buffer);

    num.NotLargSumCub(out, 3);
    QCOMPARE(buffer, QString("Числа, меньше Х, равные сумме кубов цифр:\n1"));

    [очистка буфера и  следующий тест]
}
