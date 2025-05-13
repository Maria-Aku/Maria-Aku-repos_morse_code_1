#ifndef TEST_CORRECT_MORSE_H
#define TEST_CORRECT_MORSE_H

#include <QObject>

class test_correct_morse : public QObject
{
    Q_OBJECT
public:
    explicit test_correct_morse(QObject *parent = nullptr);

    private slots:
    void test1_EmptyMessage();
    void test2_TwoLineMessage();
    void test3_MessageConsistingOfSeveralLines();
    void test4_TheMessageContainsOneCharacterOtherThanHyphenAndPoint();
    void test5_SeveralCharactersOtherThanHyphensAndPoints();
    void test6_MessageIsLongerThan20characters();
    void test7_ContainsMoreThan20CharactersAndCharactersOtherThanPointsAndHyphens();
    void test8_ContainsCharactersOtherThanPointsAndHyphensAndConsistsOfMultipleLines();
    void test9_MessageIsLongerThan20CharactersAndConsistsOfMultipleLines();
    void test10_MoreThan20CharactersMultipleLinesAndCharactersOtherThanPointsAndHyphens();
    void test11_LineHasNoErrors();
    void test12_Contains20Characters();
    void test13_Contains1Character();


signals:
};

#endif // TEST_CORRECT_MORSE_H
