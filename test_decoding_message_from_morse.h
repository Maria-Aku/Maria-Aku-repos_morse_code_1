/*!
 *\file test_decoding_message_from_morse
 *\brief  Заголовочный файл для класса test_decoding_message_from_morse
 */
#ifndef TEST_DECODING_MESSAGE_FROM_MORSE_H
#define TEST_DECODING_MESSAGE_FROM_MORSE_H

#include <QObject>

/*!
 * \brief Класс для проверки функции decoding_message_from_Morse
 *
 * Этот класс предоставляет набор тестов для проверки
 *  корректности работы функции decoding_message_from_Morse,
 *  рассматривая различные аспекты тестирования (различные последоваельности точек и дефисов)
 */
class test_decoding_message_from_Morse : public QObject
{
    Q_OBJECT
public:
    explicit test_decoding_message_from_Morse(QObject *parent = nullptr);

private slots:
    /*!
     * \brief Тест 1 : Базовый тест
     * простой тест, проверяющий базовую функциональность декодирования
     */
    void test1_BasicT();

    /*!
     * \brief Тест2 : Сообщение состоит из последовательности чередования точек и дефисов
     */
    void test2_MessageConsistOfDotsAndDashes();

    /*!
     * \brief Тест 3 :  Сообщение состоит из небольшого количества одинаковых символов (точек)
     */
    void test3_ASequenceOfIdenticalSymbols_Dots();

    /*!
     * \brief Тест 4 :   Сообщение состоит из небольшого количества одинаковых символов (тире)
     */
    void test4_ASequenceOfIdenticalSymbols_Dashes();

    /*!
     * \brief Тест 5 :  Сообщение минимальной длины (точка)
     */
    void test5_MinimumLengthOfAString_Dot();

    /*!
     * \brief Тест 6 :  Сообщение минимальной длины (тире)
     */
    void test6_MinimumLengthOfAString_Dashes();

    /*!
     * \brief Тест 7 :  Сообщение, состоящее из одного символа точки и длинной последовательности тире
     */
    void test7_AMessageMadeUpOfMultipleSymbols_ASingleDotAndALongSequenceOfDashes();

    /*!
     * \brief Тест 8 :  Сообщение, состоящее из одного символа тире и длинной последовательности точек
     */
    void test8_AMessageMadeUpOfMultipleSymbols_ASingleDashAndALongSequenceOfDots();

    /*!
     * \brief Тест 9 :  Декодирование последовательности одинаковых символов (точек)
     */
    void test9_ASequenceOfIdenticalSymbols_Dot();

    /*!
     * \brief Тест 10 :  Декодирование последовательности одинаковых символов (тире)
     */
    void test10_ASequenceOfIdenticalSymbols_Dashes();

signals:
};


#endif // TEST_DECODING_MESSAGE_FROM_MORSE_H
