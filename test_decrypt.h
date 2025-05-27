/*!
 * \file test_decrypt.h
 * \brief  Заголовочный файл для класса test_decrypt
 */
#ifndef TEST_DECRYPT_H
#define TEST_DECRYPT_H

#include <QObject>


/*!
 * \brief Класс test_decrypt предназначен для проверки функции decrypt
 *
 * Этот класс предоставляет набор тестов для проверки корректности работы функции decrypt,
 *  рассматривая различные аспекты тестирования (различная последовательность точек и дефисов,
 *  продолжение перевода части переведенной строки, наличие в алфавите одинаковых переводов)
 */
class test_decrypt : public QObject
{
    Q_OBJECT
public:
    explicit test_decrypt(QObject *parent = nullptr);

private slots:
    /*!
     * \brief Тест 1 : Базовый тест
     * простой тест, проверяющий базовую функциональность дешифрирования
     */
    void test1_Basic();

    /*!
     * \brief Тест 2 : Сообщение состоит из чередования точек и дефисов
     */
    void test2_SequencesOfAlternatingDots_Dashes();

    /*!
     * \brief Тест 3 : Сообщение состоит из двух точек
     */
    void test3_MessageConsistsOfTwoDots();

    /*!
     * \brief Тест 4 : Сообщение состоит из двух тире
     */
    void test4_MessageConsistsOfTwoHyphens();

    /*!
     * \brief Тест 5 : Сообщение состоит из одной точки
     */
    void test5_MessageConsistsOfADot();

    /*!
     * \brief Тест 6 : Сообщение состоит из одного тире
     */
    void test6_MessageConsistsOfAHyphen();

    /*!
     * \brief Тест 7 : Сообщение из нескольких символов, одна точка вначале
     * и много дефисов
     */
    void test7_MultiCharacterMessage();

    /*!
     * \brief Тест 8 : Символы в алфавите дешифруются одинаково
     */
    void test8_CharactersAlphabetDecipheredTheSameWay();

    /*!
     * \brief Тест 9 : Часть сообщения уже дешифрована
     */
    void test9_PartOfMessageAlreadyHasTranslation();

    /*!
     * \brief Тест 10: Список существующих дешифровок не пуст
     */
    void test10_TheListOfExistingTransfersIsNotEmpty();

    /*!
     * \brief Тест 11: В алфавите отсутствует символ для дешифровки
     */
    void test11_ThereIsNoTranslationSymbolInTheAlphabet();

signals:
};

#endif // TEST_DECRYPT_H
