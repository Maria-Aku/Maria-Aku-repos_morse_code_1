#include <iostream>
#include <QString>
#include <QSet>
#include <QMap>
#include <Qfile>
#include <QDebug>
#include <QTextStream>




void decrypt(const QMap <char, QString>& MorseToChar, QString decrypted, QString morse, QSet <QString>& decriptions)
{
    //Для длины префикса от 0 до (5 и не более длины строки непереведенной части)
    for (int i = 1; i <= 5 && i <= morse.length(); i++)
    {
        //Получить префикс из непереведенной части
        QString prefics_morse = morse.left(i);

        //~~~обход конетейнера~~~
        char found_letter = '\0'; // Инициализация нулевым символом,как показатель отсутствия буквы
        QMap <char, QString>::const_iterator iterator = MorseToChar.begin();
        while (iterator != MorseToChar.end())
        {
            if (iterator.value() == prefics_morse)
            {
                found_letter = iterator.key();
            }
            iterator++;

            //Если в алфавите есть буква, совпадающая с префиксом непереведенной части
            if (found_letter != '\0')
            {
                // Убрать префикс из непереведенной части и сохранить оставшуюся часть
                QString morse_withount_pref = morse.mid(i, morse.length());

                // Добавить букву к переведенной части
                QString augmented_decrypted = decrypted + found_letter;
                found_letter = '\0';
                // Если оставшаяся часть на азбуке Морзе непустая
                if (!morse_withount_pref.isEmpty())
                {
                    // Рекурсивный вызов функции
                    decrypt(MorseToChar, augmented_decrypted, morse_withount_pref, decriptions);
                }
                // Иначе
                else
                {
                    // Добавить переведенную часть в контейнер с переводами
                    decriptions.insert(augmented_decrypted);
                }
            }
        }

    }
}




int main(int argc, char*  argv[])
{

    QString message_morse= "--.";
    QSet <QString> decriptions;
    QString decrypted = "";

    //создать набор комбинаций (алфавит) перевода символов с азбуки Морзе
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, { 'C', "-.-."},
        {'D', "-.."}, {'E', "."}, {'F', "..-."},
        {'G', "--."}, {'H', "...."}, {'I', ".."},
        {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"},
        {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
        {'S', "..."}, {'T', "-"}, {'U', "..-"},
        {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"},
        {'2', "..---"}, {'3', "...--"}, {'4', "....-"},
        {'5', "....."}, {'6', "-...."}, {'7', "--..."},
        {'8', "---.."}, {'9', "----."}
    };


    decrypt(MorseToChar, decrypted, message_morse, decriptions);
    qDebug() << decriptions;


}
