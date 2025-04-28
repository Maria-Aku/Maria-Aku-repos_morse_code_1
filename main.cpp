#include <iostream>
#include <QString>
#include <QSet>
#include <QMap>
#include <Qfile>
#include <QDebug>
#include <QTextStream>

enum type_error { ManyStrings, OtherSymbols, ManySymbols, EmptyString };

struct Error
{
    enum type_error type;
    QString error_char;
    int position_error;
    QString toString() const;

    // ***ПЕРЕГРУЗКА ОПЕРАТОРА == ДОЛЖНА БЫТЬ ЗДЕСЬ, ВНУТРИ СТРУКТУРЫ**
    bool operator==(const Error& other) const {
        return (type == other.type) &&
               (position_error == other.position_error) &&
               (error_char == other.error_char);
    }
};

//seed - начальное значение для хеша
inline uint qHash(const Error& key, uint seed = 0)
{
    return qHash(key.type, seed) ^
           qHash(key.position_error, seed + 1) ^  // разный seed для каждого поля
           qHash(key.error_char, seed + 2);

}

bool correct_morse(const QString message, QSet<Error>& errors)
{
    //Если строка с сообщением пустая, то записать ошибку отсутствия символов в сообщение
    if (message.isEmpty())
    {
        Error er1;
        er1.type = EmptyString;
        errors.insert(er1);
    }
    //Иначе
    else
    {
        //получить длину сообщения
        int length_message = message.length();

        //Если в строке содержится больше 20 символов, то зафиксировать ошибку превышение допустимого количества символов
        if (length_message > 20)
        {
            Error er2;
            er2.type = ManySymbols;
            errors.insert(er2);
        }


        //Для каждого символа строки, с сообщением на азбуке Морзе
        for (int i = 0; i < length_message; i++)
        {
            //Если сообщение содержит больше одной строки сообщения (\n), то зафиксировать ошибку превышения количества строк
            if (message[i] == '\n')
            {
                Error er3;
                er3.type = ManyStrings;
                er3.position_error = 0;
                er3.error_char = 0;
                errors.insert(er3);
            }

            //Если текущий символ отличный от точки и дефиса, то зафиксировать наличие ошибки (позицию и сам символ)
            if (message[i] != '\r' && message[i] != '\n' && (message[i] != '.' && message[i] != '-'))
            {
                Error er4;
                er4.type = OtherSymbols;
                er4.error_char = message[i];
                er4.position_error = i + 1;
                errors.insert(er4);
            }
        }
    }

    //Вернуть признак наличие ошибки в сообщение
    return errors.empty() ? true : false;
}

QString Error::toString() const
{
    QString result;
    QTextStream stream(&result);

    switch (type)
    {
    case ManyStrings:
        return "Contains a message breakdown on a new line";
    case ManySymbols:
        return "The message contains more than 20 characters";
    case EmptyString:
        return "Empty message";
    case OtherSymbols:
        stream << "Symbol \'" << error_char << "\' : " << position_error;
        return result;
    default:
        return "Unknown Error";
    }
}

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



int main(int argc, char*  argv[])
{
    QString str_morse;
    QSet<Error> errors;
    QSet <QString> decriptions;

    // Проверить корректность ввода названий файлов
    bool input_correct = is_input_filename_correctly(argc, argv);


    //Если ошибок нет
    // if(input_correct)
    {
        QFile morse_file("C:/Users/Мария/Documents/decryption_morse/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/morse.txt");


        //Прочитать строку с сообщением из файла
        if (!morse_file.open(QIODevice::ReadOnly))
        {
              qWarning() << "Could not open file";
            morse_file.close();
        }
        else
        {
            QTextStream in(&morse_file);
            str_morse = in.readAll();
            morse_file.close();
        }

        //Проверить сообщение на азбуке Морзе
        bool check_morse = correct_morse(str_morse,errors);

        //Если ошибки есть, то вывести все полученные ошибки
        if (!check_morse)
        {
            QSet<Error>::iterator iter = errors.begin();
            while (iter != errors.end())
            {
                    qDebug() << iter->toString();
                    iter++;
            }
        }
        //Иначе расшифровать сообщение на азбуке Морзе и записать в файл все переводы
        else
        {
            decoding_message_from_Morse(str_morse,  decriptions);

            //проверка
            for (QSet<QString>::iterator it = decriptions.begin(); it != decriptions.end(); ++it)
            {
                qDebug() << *it << '\n';
            }

            QFile decryptedFile("C:/Users/Мария/Documents/decryption_morse/build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/debug/decription.txt");

            if (!decryptedFile.open(QIODevice::WriteOnly )) {
                qCritical() << "Could not open file for writing";
                decryptedFile.close();
                return 1;
            }

            QTextStream out(&decryptedFile);
            int i = 1;
            for (QSet<QString>::const_iterator it = decriptions.begin(); it != decriptions.end(); it++)
            {
                out << i << ") " << *it << '\n';
                i++;
            }
            decryptedFile.close();
        }
    }
    //else
    // {
    //     std::cerr << "the files have problems with the extension";
    // }
    //Иначе вывести сообщение с ошибкой ввода данных
    //Вернуть успешность завершения функции
    return 0;
}
