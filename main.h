#ifndef MAIN_H
#define MAIN_H

#include <QtCore/QCoreApplication>
#include <iostream>
#include <QString>
#include <QSet>
#include <QMap>
#include <Qfile>
#include <QDebug>
#include <QTextStream>
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

//seed — это начальное значение, которое используется в некоторых хеш-функциях для инициализации процесса хеширования.
inline uint qHash(const Error& key, uint seed = 0)
{
    return qHash(key.type, seed) ^
           qHash(key.position_error, seed + 1) ^
           qHash(key.error_char, seed + 2);

}

void decrypt(const QMap<char, QString>& MorseToChar, QString decrypted, QString morse, QSet<QString>& decriptions);
void decoding_message_from_Morse(QString message_morse, QSet <QString>& decriptions);
bool correct_morse(const QString message, QSet<Error> & errors);

QString errorTypeToString(type_error type);
#endif // MAIN_H
