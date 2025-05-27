#include "test_decrypt.h"
#include "main.h"

test_decrypt::test_decrypt(QObject *parent)
    : QObject{parent}
{}

QMap<QString, QMap<char, QString>> allMorseToChars; // Хранилище всех карт

QMap<char, QString> getMorseToChar(const QString& id)  {
    return allMorseToChars.value(id);// извлечение значений карты
}

void test_decrypt::initTestCase() {
    // Инициализация карт символов
    QMap<char, QString> morseToChar1;
    morseToChar1['A'] = ".-";
    morseToChar1['B'] = "-...";
    morseToChar1['C'] = "-.-.";
    morseToChar1['D'] = "-..";
    morseToChar1['E'] = ".";
    morseToChar1['F'] = "..-.";
    morseToChar1['G'] = "--.";
    morseToChar1['H'] = "....";
    morseToChar1['I'] = "..";
    morseToChar1['J'] = ".---";
    morseToChar1['K'] = "-.-";
    morseToChar1['L'] = ".-..";
    morseToChar1['M'] = "--";
    morseToChar1['N'] = "-.";
    morseToChar1['O'] = "---";
    morseToChar1['P'] = ".--.";
    morseToChar1['Q'] = "--.-";
    morseToChar1['R'] = ".-.";
    morseToChar1['S'] = "...";
    morseToChar1['T'] = "-";
    morseToChar1['U'] = "..-";
    morseToChar1['V'] = "...-";
    morseToChar1['W'] = ".--";
    morseToChar1['X'] = "-..-";
    morseToChar1['Y'] = "-.--";
    morseToChar1['Z'] = "--..";
    morseToChar1['1'] = ".----";
    morseToChar1['2'] = "..---";
    morseToChar1['3'] = "...--";
    morseToChar1['4'] = "....-";
    morseToChar1['5'] = ".....";
    morseToChar1['6'] = "-....";
    morseToChar1['7'] = "--...";
    morseToChar1['8'] = "---..";
    morseToChar1['9'] = "----.";
    morseToChar1['0'] = "-----";
    allMorseToChars["case1"] = morseToChar1;

    QMap<char, QString> morseToChar2;
    morseToChar2['D'] = ".";
    morseToChar2['S'] = ".";
    allMorseToChars["case2"] = morseToChar2;

    QMap<char, QString> morseToChar3;
    morseToChar3['A'] = ".-";
    morseToChar3['E'] = ".";
    morseToChar3['T'] = "-";
    morseToChar3['I'] = "..";
    allMorseToChars["case3"] = morseToChar3;

    QMap<char, QString> morseToChar4;
    morseToChar4['A'] = ".";
    allMorseToChars["case4"] = morseToChar4;
}

void test_decrypt::add_data() {
    QTest::addColumn<QString>("morse");
    QTest::addColumn<QString>("decrypted");
    QTest::addColumn<QString>("morseToCharId"); // Передаем ID карты
    QTest::addColumn<QSet<QString>>("decriptions");
    QTest::addColumn<QSet<QString>>("expected_decriptions");


    //Создаем строки-тесты и заполняем данными
    /*!
     * \brief Тест 1 : Базовый тест
     * простой тест, проверяющий базовую функциональность дешифрирования
     */
    QTest::newRow("test1_Basic") << ".---" << "" << "case1" << QSet<QString>{}<< QSet<QString>{"ETTT", "ETM", "AM", "ATT", "EMT", "WT", "EO", "J"};

    /*!
     * \brief Тест 2 : Сообщение состоит из чередования точек и дефисов
     */
    QTest::newRow("test2_SequencesOfAlternatingDots_Dashes") << ".-.-." << "" << "case1"  << QSet<QString>{}<< QSet<QString>{ "ETETE", "ETEN", "ENTE", "ETAE", "ENN", "EKE", "EC", "AETE", "AEN", "ETR", "AAE", "AR", "RTE", "RN"};


    /*!
     * \brief Тест 3 : Сообщение состоит из двух точек
     */
    QTest::newRow("test3_MessageConsistsOfTwoDots") << ".." << "" << "case1"  << QSet<QString>{}<< QSet<QString>{ "EE", "I"};

    /*!
     * \brief Тест 4 : Сообщение состоит из двух тире
     */
    QTest::newRow("test4_MessageConsistsOfTwoHyphens") << "--" << "" << "case1"  << QSet<QString>{}<< QSet<QString>{"TT", "M"};

    /*!
     * \brief Тест 5 : Сообщение состоит из одной точки
     */
    QTest::newRow("test5_MessageConsistsOfADot") << "." << "" << "case1"  << QSet<QString>{}<< QSet<QString>{"E"};

    /*!
     * \brief Тест 6 : Сообщение состоит из одного тире
     */
    QTest::newRow("test6_MessageConsistsOfAHyphen") << "-" << "" << "case1"  << QSet<QString>{}<< QSet<QString>{"T"};

    /*!
     * \brief Тест 7 : Сообщение из нескольких символов, одна точка вначале
     * и много дефисов
     */
    QTest::newRow("test7_MultiCharacterMessage") << ".----" << "" << "case1"  << QSet<QString>{}<< QSet<QString>{"ETTTT","ATTT","ETMT","AMT","ETO","AO","EMTT","WTT","EMM","WM","EOT","JT","1","ETTM","ATM"};

    /*!
     * \brief Тест 8 : Символы в алфавите дешифруются одинаково
     */
    QTest::newRow("test8_CharactersAlphabetDecipheredTheSameWay") << "." << "" << "case2"  << QSet<QString>{}<< QSet<QString>{"D", "S"};

    /*!
     * \brief Тест 9 : Часть сообщения уже дешифрована
     */
    QTest::newRow("test9_PartOfMessageAlreadyHasTranslation") << ".." << "AT" << "case3"  << QSet<QString>{}<< QSet<QString>{"ATEE", "ATI"};

    /*!
     * \brief Тест 10: Список существующих дешифровок не пуст
     */
    QTest::newRow("test10_TheListOfExistingTransfersIsNotEmpty") << "--" << "A" << "case1"  << QSet<QString>{"ETTT", "ETM", "EMT", "EO"}<< QSet<QString>{"ETTT", "ETM", "AM", "ATT", "EMT", "EO"};

    /*!
     * \brief Тест 11: В алфавите отсутствует символ для дешифровки
     */
    QTest::newRow("test11_ThereIsNoTranslationSymbolInTheAlphabet") << "-" << "" << "case4"  << QSet<QString>{}<< QSet<QString>{};

}

void test_decrypt::add() {
    QFETCH(QString, morse);
    QFETCH(QString, decrypted);
    QFETCH(QString, morseToCharId); // Получаем ID карты
    QFETCH(QSet<QString>, decriptions);
    QFETCH(QSet<QString>, expected_decriptions);

    // Получаем карту символов по ID
    QMap<char, QString> MorseToChar = getMorseToChar(morseToCharId);


    decrypt(MorseToChar, decrypted, morse, decriptions);

    QCOMPARE(decriptions.size(), expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions;
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions;

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty()) {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty()) {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty()) {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }

    QCOMPARE(decriptions, expected_decriptions);
}



