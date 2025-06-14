#include "main.h"
#include "test_decrypt.h"
#include "test_decoding_message_from_morse.h"
#include "test_correct_morse.h"

bool correct_morse(const QString message, QSet<Error>& errors)
{
    //Если строка с сообщением пустая, то записать ошибку отсутствия символов в сообщение
    if (message.isEmpty())
    {
        Error er1;
        er1.type = EmptyString;
        er1.position_error = -1;
        er1.error_char = "";
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
            er2.position_error = -1;
            er2.error_char = "";
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
                er3.position_error = -1;
                er3.error_char = "";
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
    switch (type)
    {
    case ManyStrings:
        return "Программа принимает на вход файлы из одной строки. Необходимо изменить сообщение или разбить его на два файла.";
    case ManySymbols:
        return "Входной файл содержит количества символов, которое больше допустимого (20)";
    case EmptyString:
        return "Выбранный файл пуст";
    case OtherSymbols:qDebug() << "Ошибка";
       return QString("Файл с сообщением содержит символы отличные от дефиса и точки. Символ \' %1 \' : %2").arg(error_char).arg(position_error);

    default:
        return "Неизвестная ошибка";
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
            QString filename = QString(argv[i]);

            bool extension_error = is_extensive_ok(filename, extension);
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
    if(input_correct)
    {
        QFile morse_file(argv[1]);

        // Проверка открытия файла
        if (!morse_file.open(QIODevice::ReadOnly))
        {
            qWarning() << "Неверно указан файл с входными данными. Возможно, файл не существует.";
            morse_file.close();
        }
        else
        {
            //Прочитать строку с сообщением из файла
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
                QString res = iter->toString();
                qInfo() << res;
                iter++;
            }
        }
        //Иначе расшифровать сообщение на азбуке Морзе и записать в файл все переводы
        else
        {
            decoding_message_from_Morse(str_morse,  decriptions);

            QFile decryptedFile(argv[2]);

            if (!decryptedFile.open(QIODevice::WriteOnly )) {
                qCritical() << "Неверно указан файл для выходных данных. Возможно, указанного расположения не существует или нет прав на запись.";
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
    //Иначе вывести сообщение с ошибкой ввода данных
    else
    {
        qInfo() << "Неправильно введено расширение файла. Должно быть .txt" << '\n';
    }


    //Вернуть успешность завершения функции
    QTest::qExec(new test_decrypt);
    QTest::qExec(new test_decoding_message_from_Morse);
    QTest::qExec(new test_correct_morse);
    return 0;
}

QString errorTypeToString(type_error type) {
    switch (type) {
    case EmptyString:   return "EmptyString";
    case ManySymbols:   return "ManySymbols";
    case ManyStrings:   return "ManyStrings";
    case OtherSymbols:   return "OtherSymbols";
    default:            return "UnknownErrorType";
    }
}
