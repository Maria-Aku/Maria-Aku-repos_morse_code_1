/*!
 * \file test_correct_morse.h
 * \brief Заголовочный файл для класса test_correct_morse
 *
 * Этот файл содержит объявление класса test_correct_morse, который предназначен
 * для тестирования функции `correct_morse` (которая,проверяет
 * правильность строк с сообщениями азбуки Морзе).
 */

#ifndef TEST_CORRECT_MORSE_H
#define TEST_CORRECT_MORSE_H

#include <QObject>
/*!
 * \brief Класс для тестирования функции correct_morse
 *
 * Этот класс предоставляет набор тестов для проверки корректности работы функции correct_morse,
 * включая различные виды ошибок(пустая строка, символы отличные от точек и дефисов, перенос строки,
 *  количество символов больше 20), а также различное их сочетание
 */

class test_correct_morse : public QObject
{
    Q_OBJECT
public:
    explicit test_correct_morse(QObject *parent = nullptr);

    private slots:

    /*!
     * \brief Тест 1 : Проверка на пустую строку
     */
    void test1_EmptyMessage();

    /*!
     * \brief Тест 2 : Проверка сообщения из двух строк
     */
    void test2_TwoLineMessage();

    /*!
     * \brief  Тест 3 : Проверка сообщения, состоящего из нескольких строк
     */
    void test3_MessageConsistingOfSeveralLines();

    /*!
     * \brief  Тест 4 : Сообщение содержит один символ, отличный от тире и точки
     */
    void test4_TheMessageContainsOneCharacterOtherThanHyphenAndPoint();

    /*!
     * \brief Тест 5 : Сообщение содержит несколько символов, отличных от тире и точек
     */
    void test5_SeveralCharactersOtherThanHyphensAndPoints();

    /*!
     * \brief Тест 6 : Проверка сообщения, превышающего длину 20 символов
     */
    void test6_MessageIsLongerThan20characters();

    /*!
     * \brief  Тест 7 : Сообщение содержит более 20 символов и символы, отличные от точек и тире
     */
    void test7_ContainsMoreThan20CharactersAndCharactersOtherThanPointsAndHyphens();

    /*!
     * \brief Тест 8 : Сообщение содержит символы отличные от точек и дефисов, и состоит из нескольких строк
     */
    void test8_ContainsCharactersOtherThanPointsAndHyphensAndConsistsOfMultipleLines();

    /*!
     * \brief Тест 9 : Сообщение длиннее 20 символов и состоит из нескольких строк
     */
    void test9_MessageIsLongerThan20CharactersAndConsistsOfMultipleLines();

    /*!
     * \brief Тест 10 : Сообщение содержит более 20 символов, несколько строк и символы, отличные от точек и тире
     */
    void test10_MoreThan20CharactersMultipleLinesAndCharactersOtherThanPointsAndHyphens();

    /*!
     * \brief Тест 11 :  Строка не содержит ошибок
     */
    void test11_LineHasNoErrors();

    /*!
     * \brief Тест 12 : Сообщение содержит ровно 20 символов
     */
    void test12_Contains20Characters();

    /*!
     * \brief Сообщение содержит 1 символ
     */
    void test13_Contains1Character();


signals:
};

#endif // TEST_CORRECT_MORSE_H
