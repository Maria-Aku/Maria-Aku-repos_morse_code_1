#ifndef MAIN_H
#define MAIN_H

#include <QString>
#include <QSet>
#include <QMap> // Используем QMap
#include <QTest> // Обязательно для QCOMPARE
enum type_error { ManyStrings, OtherSymbols, ManySymbols, EmptyString };

struct Error
{
    enum type_error type;
    QString error_char;
    int position_error;
    QString toString() const;

    // Перегрузка операции ==
    bool operator==(const Error& other) const {
        return (type == other.type) &&
               (position_error == other.position_error) &&
               (error_char == other.error_char);
    }
};


void decrypt(const QMap<char, QString>& MorseToChar, QString decrypted, QString morse, QSet<QString>& decriptions);
void decoding_message_from_Morse(QString message_morse, QSet <QString>& decriptions);
bool correct_morse(const QString message, QSet<Error> & errors);
#endif // MAIN_H
