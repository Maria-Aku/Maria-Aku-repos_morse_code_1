/*!
/*! \mainpage Программа для перевода из Азбуки Морзе
 *
 * \section  Введение
 * Данная программа предназначена для перевода сообщений из азбуки Морзе в набор букв латинского алфавита и цифр.
 *Программа должна переводить сообщение на азбуке Морзе, представляя все возможные способы его расшифровки.
 *
* \file main.h - заголовочный файл, содержащий описание функций программы
* \file main.cpp - файл содержит всю реальзацию программы
*/

#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QCoreApplication>
#include <iostream>
#include <QString>
#include <QSet>
#include <Qfile>
#include <QDebug>
#include <QTextStream>
#include <QTest> // Обязательно для QCOMPARE


/*!
 * \brief Перечисление для ошибок, которые могут находиться в строке с сообщением на Азбуке морзе
 */
enum type_error { ManyStrings,///<Слишком много строк
                  OtherSymbols,///<Другие недопустимые символы
                  ManySymbols,///<Слишком много символов в одной строке
                  EmptyString ///<Пустая строка
};

/*!
 * \brief Структура, описывающая информацию об ошибке в строке.
 *
 *  Содержит тип ошибки, символ, вызвавший ошибку, и позицию ошибки в строке.
 */
struct Error
{
    /*!
     * \brief Тип ошибки
     */
    enum type_error type;

    /*!
     * \brief Символ, который вызвал ошибку
     */
    QString error_char;

    /*!
     * \brief Позиция ошибки в строке
     */
    int position_error;

    /*!
     * \brief Преобразует информацию об ошибке в строку для удобного отображения
     */
    QString toString() const;

    // Перегрузка операции ==
    /*!
     * \brief  Перегрузка operator == для сравнения двух объектов Error
     * \param[in] other Передаваемый объект для сравнения
     * \return возвращает true если объекты равны, иначе false
     */
    bool operator==(const Error& other) const {
        return (type == other.type) &&
               (position_error == other.position_error) &&
               (error_char == other.error_char);
    }
};


//seed — это начальное значение, которое используется в некоторых хеш-функциях для инициализации процесса хеширования.
/*!
 * \brief qHash получение хеш-значение для структуры
 *
 * Эта функция предоставляет хэш-функцию для структуры Error, что позволяет
 * использовать экземпляры Error в хэш-таблице (QSet).
 *
 * \param[in] key - экземпляр ошибки структуры Error
 * \param[in] seed -значение, обеспечивающее уникальность хеш-кода
 * \return хеш-значение для структуры
 */
inline uint qHash(const Error& key, uint seed = 0)
{
    return qHash(key.type, seed) ^
           qHash(key.position_error, seed + 1) ^
           qHash(key.error_char, seed + 2);

}

/*!
 * \brief decrypt - рекурсивная функция перевода
* \param[in] MorseToChar - предназначен для хранения соответствия между символом (буквой) и кодом на азбуке Морзе
* \param[in] decrypted – переведенная часть строки
* \param[in] morse – оставшаяся часть
* \param[out] decriptions - хранит все найденные строки переводов комбинаций символов на азбуке Морзе
*/

void decrypt(const QMap<char, QString>& MorseToChar, QString decrypted, QString morse, QSet<QString>& decriptions);


/*!
 *\brief decoding_message_from_Morse - функция перевода сообщения с азбуки Морзе
* \param[in]  message_morse – строка, содержащая сообщение на азбуке Морзе
* \param[out] decriptions - хранит все найденные строки переводов комбинаций символов на азбуке Морзе
*/
void decoding_message_from_Morse(QString message_morse, QSet <QString>& decriptions);


/*!
*Функция проверки сообщения на азбуке Морзе
* \param[in]  message – строка, содержащая сообщение на азбуке Морзе
* \param[out] errors – хранит все допустимые ошибки в сообщение с азбукой Морзе
* \return возвращает наличие ошибки
*/
bool correct_morse(const QString message, QSet<Error> & errors);

/*!
*\brief is_extensive_ok - функция проверки расширения
*\param[in] filename – строк, содержащая название файла
*\param[in] extension – необходимое расширение
*\return true, если расширение файла соответствует заданному иначе false
*/
bool is_extensive_ok(const QString filename, const QString extension);

/*!
*\brief is_input_filename_correctly - функция проверки расширений передаваемых парамтров
* Проверяет, что расширения файлов - ".txt"
*\param[in] argс – количество переданных аргументов командной строки
*\param[in] argv [] – аргументы командной строки
*\return true, если аргументы корректны, иначе false
*/
bool is_input_filename_correctly (int argc, char* argv[]);

/*!
* \brief errorTypeToString - метод перобразования типа ошибки из числового формата в строку
* \param[in] type - тип ошибки в числовом формате
* \return возвращает тип ошибки в виде строки
*/
QString errorTypeToString(type_error type);
#endif // MAIN_H
