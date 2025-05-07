#include "test_decrypt.h"
#include "main.h"
#include <QString>
#include <QSet>
#include <QMap>
#include <QDebug>

test_decrypt::test_decrypt(QObject *parent)
    : QObject{parent}
{}

void test_decrypt::testBasic()
{
    QString morse = ".---";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "ETTT", "ETM" ,"AM" ,"ATT", "EMT", "WT", "EO", "J"};

    QCOMPARE(decriptions, expected_decriptions);


}

void test_decrypt::testTheMessageConsistsTwoLines()
{
    QString morse = ".-.-.";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "ETETE", "ETEN", "ENTE", "ETAE", "ENN", "EKE", "EC", "AETE", "AEN", "ETR", "AAE", "AR", "RTE", "RN"};

    QCOMPARE(decriptions, expected_decriptions);

}


void test_decrypt::testMessageConsistsOfTwoDots()
{
    QString morse = "..";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "EE", "I"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testMessageConsistsOfTwoHyphens()
{
    QString morse = "--";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "TT", "M"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testMessageConsistsOfADot()
{
    QString morse = ".";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "E"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testMessageConsistsOfAHyphen()
{
    QString morse = "-";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={ "T"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testMultiCharacterMessage()
{
    QString morse = ".----";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={"ETTTT","ATTT","ETMT","AMT","ETO","AO","EMTT","WTT","EMM","WM","EOT","JT","1","ETTM","ATM"};

    QCOMPARE(decriptions, expected_decriptions);

}


void test_decrypt::CharactersAlphabetDecipheredTheSameWay()
{
    QString morse = ".";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = { {'D', "."}, {'S', "."}};

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={"D", "S"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testPartOfMessageAlreadyHasTranslation()
{
    QString morse = "..";
    QString decrypted = "AT";
    QMap<char, QString> MorseToChar = { {'A', ".-"}, {'E', "."}, {'T', "-"}, {'I', ".."}};

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={"ATEE", "ATI"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::testTheListOfExistingTransfersIsNotEmpty()
{
    QString morse = "--";
    QString decrypted = "A";
    QMap<char, QString> MorseToChar = {
        {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
        {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
        {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
        {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
        {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
        {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
        {'Y', "-.--"}, {'Z', "--.."}, {'1', ".----"}, {'2', "..---"},
        {'3', "...--"}, {'4', "....-"}, {'5', "....."}, {'6', "-...."},
        {'7', "--..."}, {'8', "---.."}, {'9', "----."}
    };

    QSet<QString> decriptions{"ETTT", "ETM", "EMT", "EO"};
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={"ETTT", "ETM", "AM", "ATT", "EMT", "EO"};

    QCOMPARE(decriptions, expected_decriptions);

}

void test_decrypt::ThereIsNoTranslationSymbolInTheAlphabet()
{
    QString morse = "-";
    QString decrypted = "";
    QMap<char, QString> MorseToChar = { {'A', "."}};

    QSet<QString> decriptions;
    decrypt(MorseToChar, decrypted, morse, decriptions);

    QSet<QString> expected_decriptions ={};

    QCOMPARE(decriptions, expected_decriptions);

}
