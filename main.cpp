#include <iostream>
#include <QString>
#include <QSet>
#include <QMap>
#include <Qfile>
#include <QDebug>
#include <QTextStream>

bool is_extensive_ok(const QString filename, const QString extension)
{
    QString got_extension;

    // Найти тип введенном названии файла
    int last_point = filename.lastIndexOf('.');

    if (last_point != -1)
    {
        got_extension = filename.mid(last_point + 1);
    }
    else
    {
        return false;
    }

    //Если полученный тип совпадает с введенным типом тип, ввернуть отсутствие ошибки иначе вернуть ошибка существует
    return got_extension == extension ? true : false;
}

bool is_input_filename_correctly(int argc, char* argv[])
{
    int error = 0;
    // Если количество аргументов не равно 3х, то зафиксировать наличие ошибки
    if (argc != 3)
    {
        error++;
    }
    // Иначе
    else
    {
        //..расширение файла (.txt)
        QString extension = "txt";

        //Для каждого аргумента названий файлов, начиная с первого, пока есть аргументы
        for (int i = 1; i < argc; i++)
        {
            // Проверить, что расширение файла - txt
            qDebug() << argv[i];
            bool extension_error = is_extensive_ok(argv[i], extension);
            // Если ошибка есть, увеличиваем счетчик наличие ошибки в расширении
            if (extension_error == false)
            {
                error++;
            }
        }
    }
    qDebug() << error ;
    //Если есть ошибки во входной строке, вернуть существование ошибки иначе вернуть ее отсутствие
    return error == 0;
}


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

void decoding_message_from_Morse(QString message_morse, QSet <QString>& decriptions)
{
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

    //Поиск переводов сообщения на азбуке Морзе
    decrypt(MorseToChar, decrypted, message_morse, decriptions);
}



int main()
{
    char* args[] = { "program.exe", "file1.txt", "file2.txt" };
    int argc = 3;
    bool ok = is_input_filename_correctly(argc,args);
    qDebug() << ok ;


    // for (int i = 0; i < argc; i++)
    // {
    //     std::cout << argv[i];
    // }

    // // Проверить корректность ввода названий файлов
    // bool input_correct = is_input_filename_correctly(argc, argv);


    // //Если ошибок нет
    // if(input_correct)
    // {
    //     QFile morse_file(argv[1]);

    //     //Прочитать строку с сообщением из файла
    //     if (!morse_file.open(QIODevice::ReadOnly))
    //     {
    //           qWarning() << "Could not open file";
    //     }
    //     else
    //     {
    //         QTextStream in(&morse_file);
    //         QString str_morse = in.readAll();
    //     }


    //     //Проверить сообщение на азбуке Морзе

    //     //Если ошибки есть, то вывести все полученные ошибки
    //     //Иначе расшифровать сообщение на азбуке Морзе и записать в файл все переводы
    // }

    //Иначе вывести сообщение с ошибкой ввода данных
    //Вернуть успешность завершения функции

}
