#include "test_correct_morse.h"
#include "main.h"
#include <QString>
#include <QSet>
#include <QMap>
#include <QDebug>
test_correct_morse::test_correct_morse(QObject *parent)
    : QObject{parent}
{}

void test_correct_morse::test1_EmptyMessage()
{
    const QString message = "";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;
    Error expect_error;
    expect_error.type = EmptyString;
    expect_error.position_error = -1;
    expect_error.error_char = "";
   expectedErrors.insert(expect_error);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());

    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }

}

 void test_correct_morse::test2_TwoLineMessage()
{
     const QString message = ".-.--\n---.-.";
     QSet<Error>  errors;
     bool correct = correct_morse(message, errors);

     QSet<Error> expectedErrors;
     // Ожидаемые результаты
     bool expect_correct = false;
     Error expect_error;
     expect_error.type = ManyStrings;
     expect_error.position_error = -1;
     expect_error.error_char = "";
     expectedErrors.insert(expect_error);

     // Проверки
     QCOMPARE(correct, expect_correct);
     QCOMPARE(errors.size(), expectedErrors.size());

     for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
         const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
         QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
         if (error_iterator == errors.end())
         {
             qDebug() << "Actual errors:";
             for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                 const Error& error = *it;
                 qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
             }
         }
         QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
     }
}
 void test_correct_morse::test3_MessageConsistingOfSeveralLines()
{
     const QString message = ".-.\n-\n--\n.-.";
     QSet<Error>  errors;
     bool correct = correct_morse(message, errors);

     QSet<Error> expectedErrors;
     // Ожидаемые результаты
     bool expect_correct = false;
     Error expect_error;
     expect_error.type = ManyStrings;
     expect_error.position_error = -1;
     expect_error.error_char = "";
     expectedErrors.insert(expect_error);

     // Проверки
     QCOMPARE(correct, expect_correct);
     QCOMPARE(errors.size(), expectedErrors.size());

     for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
         const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
         QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
         if (error_iterator == errors.end())
         {
             qDebug() << "Actual errors:";
             for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                 const Error& error = *it;
                 qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
             }
         }
         QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
     }
}
void test_correct_morse::test4_TheMessageContainsOneCharacterOtherThanHyphenAndPoint()
{
    const QString message = ".A-...-..---";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;
    Error expect_error;
    expect_error.type = OtherSymbols;
    expect_error.position_error = 2;
    expect_error.error_char = "A";
    expectedErrors.insert(expect_error);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());

    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }
}
 void test_correct_morse::test5_SeveralCharactersOtherThanHyphensAndPoints()
{
     const QString message = ". A-...-/..---";
     QSet<Error>  errors;
     bool correct = correct_morse(message, errors);

     QSet<Error> expectedErrors;
     // Ожидаемые результаты
     bool expect_correct = false;

     Error expect_error1;
     expect_error1.type = OtherSymbols;
     expect_error1.position_error = 2;
     expect_error1.error_char = " ";
     expectedErrors.insert(expect_error1);

     Error expect_error2;
     expect_error2.type = OtherSymbols;
     expect_error2.position_error = 3;
     expect_error2.error_char = "A";
     expectedErrors.insert(expect_error2);

     Error expect_error3;
     expect_error3.type = OtherSymbols;
     expect_error3.position_error = 9;
     expect_error3.error_char = "/";
     expectedErrors.insert(expect_error3);

     // Проверки
     QCOMPARE(correct, expect_correct);
     QCOMPARE(errors.size(), expectedErrors.size());


     for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
         const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
         QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
         if (error_iterator == errors.end())
         {
             qDebug() << "Actual errors:";
             for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                 const Error& error = *it;
                 qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
             }
         }
         QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
     }
}
 void test_correct_morse::test6_MessageIsLongerThan20characters()
{
     const QString message = "-.---...------.---...---..---..-----.---";
     QSet<Error>  errors;
     bool correct = correct_morse(message, errors);

     QSet<Error> expectedErrors;
     // Ожидаемые результаты
     bool expect_correct = false;
     Error expect_error;
     expect_error.type = ManySymbols;
     expect_error.position_error = -1;
     expect_error.error_char = "";
     expectedErrors.insert(expect_error);

     // Проверки
     QCOMPARE(correct, expect_correct);
     QCOMPARE(errors.size(), expectedErrors.size());

     for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
         const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
         QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
         if (error_iterator == errors.end())
         {
             qDebug() << "Actual errors:";
             for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                 const Error& error = *it;
                 qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
             }
         }
         QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
     }
}
void test_correct_morse::test7_ContainsMoreThan20CharactersAndCharactersOtherThanPointsAndHyphens()
{

    const QString message = "-.2-A--...------.---...---..---..-----.---";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;

    Error expect_error1;
    expect_error1.type = OtherSymbols;
    expect_error1.position_error = 3;
    expect_error1.error_char = "2";
    expectedErrors.insert(expect_error1);

    Error expect_error2;
    expect_error2.type = OtherSymbols;
    expect_error2.position_error = 5;
    expect_error2.error_char = "A";
    expectedErrors.insert(expect_error2);

    Error expect_error3;
    expect_error3.type = ManySymbols;
    expect_error3.position_error = -1;
    expect_error3.error_char = "";
    expectedErrors.insert(expect_error3);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());


    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }
}
void test_correct_morse::test8_ContainsCharactersOtherThanPointsAndHyphensAndConsistsOfMultipleLines()
{
    const QString message = "-.2-\n-.\nA-Й\n..-----";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;

    Error expect_error1;
    expect_error1.type = OtherSymbols;
    expect_error1.position_error = 3;
    expect_error1.error_char = "2";
    expectedErrors.insert(expect_error1);

    Error expect_error2;
    expect_error2.type = OtherSymbols;
    expect_error2.position_error = 9;
    expect_error2.error_char = "A";
    expectedErrors.insert(expect_error2);

    Error expect_error3;
    expect_error3.type = ManyStrings;
    expect_error3.position_error = -1;
    expect_error3.error_char = "";
    expectedErrors.insert(expect_error3);

    Error expect_error4;
    expect_error4.type = OtherSymbols;
    expect_error4.position_error = 11;
    expect_error4.error_char = "Й";
    expectedErrors.insert(expect_error4);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());


    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }
}
void test_correct_morse::test9_MessageIsLongerThan20CharactersAndConsistsOfMultipleLines()
{
    const QString message = "-.---.\n..------\n.---\n...---..\n--.---";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;

    Error expect_error2;
    expect_error2.type = ManySymbols;
    expect_error2.position_error = -1;
    expect_error2.error_char = "";
    expectedErrors.insert(expect_error2);

    Error expect_error3;
    expect_error3.type = ManyStrings;
    expect_error3.position_error = -1;
    expect_error3.error_char = "";
    expectedErrors.insert(expect_error3);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());


    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }
}
void test_correct_morse::test10_MoreThan20CharactersMultipleLinesAndCharactersOtherThanPointsAndHyphens()
{
    const QString message = "-.--A-.\n..4------\n.-1--\n...---..\n--.---";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = false;

    Error expect_error1;
    expect_error1.type = OtherSymbols;
    expect_error1.position_error = 5;
    expect_error1.error_char = "A";
    expectedErrors.insert(expect_error1);

    Error expect_error2;
    expect_error2.type = ManySymbols;
    expect_error2.position_error = -1;
    expect_error2.error_char = "";
    expectedErrors.insert(expect_error2);

    Error expect_error3;
    expect_error3.type = ManyStrings;
    expect_error3.position_error = -1;
    expect_error3.error_char = "";
    expectedErrors.insert(expect_error3);

    Error expect_error4;
    expect_error4.type = OtherSymbols;
    expect_error4.position_error = 11;
    expect_error4.error_char = "4";
    expectedErrors.insert(expect_error4);

    Error expect_error5;
    expect_error5.type = OtherSymbols;
    expect_error5.position_error = 21;
    expect_error5.error_char = "1";
    expectedErrors.insert(expect_error5);

    // Проверки
    QCOMPARE(correct, expect_correct);
    QCOMPARE(errors.size(), expectedErrors.size());


    for (QSet<Error>::const_iterator exp_iterator = expectedErrors.constBegin(); exp_iterator != expectedErrors.constEnd(); ++exp_iterator) {
        const Error& expectedError = *exp_iterator; // Получаем ошибку, на которую указывает итератор
        QSet<Error>::const_iterator error_iterator = errors.find(expectedError); // Используем errors.find() для QSet
        if (error_iterator == errors.end())
        {
            qDebug() << "Actual errors:";
            for (QSet<Error>::const_iterator it = errors.constBegin(); it != errors.constEnd(); ++it) {
                const Error& error = *it;
                qDebug() << error.error_char << error.position_error << errorTypeToString(error.type);
            }
        }
        QVERIFY2(error_iterator != errors.end(), QString("Expected error %1 not found ").arg(expectedError.toString()).toUtf8());// проверка, был ли найден реальный объект внутри контейнера
    }
}
void test_correct_morse::test11_LineHasNoErrors()
{
    const QString message = "-.---.";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = true;
     QCOMPARE(correct, expect_correct);
}
void test_correct_morse::test12_Contains20Characters()
{
    const QString message = "-.---...------.---..";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = true;
    QCOMPARE(correct, expect_correct);
}
void test_correct_morse::test13_Contains1Character()
{
    const QString message = "-";
    QSet<Error>  errors;
    bool correct = correct_morse(message, errors);

    QSet<Error> expectedErrors;
    // Ожидаемые результаты
    bool expect_correct = true;
    QCOMPARE(correct, expect_correct);
}
