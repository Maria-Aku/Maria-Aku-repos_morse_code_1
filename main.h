#ifndef MAIN_H
#define MAIN_H

#include <QString>
#include <QSet>
#include <QMap> // Используем QMap

void decrypt(const QMap<char, QString>& MorseToChar, QString decrypted, QString morse, QSet<QString>& decriptions);

#endif // MAIN_H
