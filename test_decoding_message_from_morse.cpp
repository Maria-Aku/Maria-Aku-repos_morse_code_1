#include "test_decoding_message_from_morse.h"
#include "main.h"

test_decoding_message_from_Morse::test_decoding_message_from_Morse(QObject *parent)
    : QObject{parent}
{}

void test_decoding_message_from_Morse::test1_BasicT(){
    QString message_morse = ".---";
    QSet <QString> decriptions;
    decoding_message_from_Morse( message_morse, decriptions);

    QSet <QString> expected_decriptions = { "ETTT", "ETM" ,"AM" ,"ATT", "EMT", "WT", "EO", "J"};

    QCOMPARE(decriptions.size(),expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty())
        {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty())
        {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }

    QCOMPARE(decriptions, expected_decriptions);
}
 void test_decoding_message_from_Morse::test2_MessageConsistOfDotsAndDashes()
{
     QString message_morse = ".-.-.";
     QSet <QString> decriptions;
     decoding_message_from_Morse( message_morse, decriptions);

     QSet <QString> expected_decriptions = { "ETETE", "ETEN" ,"ENTE" ,"ENN", "EKE", "EC", "AETE", "AEN", "AAE", "AR", "RTE", "RN", "ETR", "ETAE" };

     QCOMPARE(decriptions.size(),expected_decriptions.size());
     QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
     QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

     if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
         qDebug() << "Mismatch of sets!";

         if (!missing_in_actual.isEmpty())
         {
             qDebug() << "Missing from the received result: " << missing_in_actual;
         }

         if (!unexpected_in_actual.isEmpty())
        {
             qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }
      QCOMPARE(decriptions, expected_decriptions);
}
void test_decoding_message_from_Morse::test3_ASequenceOfIdenticalSymbols_Dots()
{
    QString message_morse = "..";
    QSet <QString> decriptions;
    decoding_message_from_Morse( message_morse, decriptions);

    QSet <QString> expected_decriptions = { "EE", "I"  };

    QCOMPARE(decriptions.size(),expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty())
        {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty())
        {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }

     QCOMPARE(decriptions, expected_decriptions);
}

void test_decoding_message_from_Morse::test4_ASequenceOfIdenticalSymbols_Dashes()
{
    QString message_morse = "--";
    QSet <QString> decriptions;
    decoding_message_from_Morse( message_morse, decriptions);

    QSet <QString> expected_decriptions = { "TT", "M"  };

    QCOMPARE(decriptions.size(),expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty())
        {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty())
        {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }
     QCOMPARE(decriptions, expected_decriptions);
}
 void test_decoding_message_from_Morse::test5_MinimumLengthOfAString_Dot()
{
     QString message_morse = ".";
     QSet <QString> decriptions;
     decoding_message_from_Morse( message_morse, decriptions);

     QSet <QString> expected_decriptions = { "E" };

     QCOMPARE(decriptions.size(),expected_decriptions.size());
     QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
     QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

     if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
     {
         qDebug() << "Mismatch of sets!";

         if (!missing_in_actual.isEmpty())
         {
             qDebug() << "Missing from the received result: " << missing_in_actual;
         }

         if (!unexpected_in_actual.isEmpty())
         {
             qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
         }
     }
 QCOMPARE(decriptions, expected_decriptions);
}
 void test_decoding_message_from_Morse::test6_MinimumLengthOfAString_Dashes()
{
     QString message_morse = "-";
     QSet <QString> decriptions;
     decoding_message_from_Morse( message_morse, decriptions);

     QSet <QString> expected_decriptions = { "T" };

     QCOMPARE(decriptions.size(),expected_decriptions.size());
     QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
     QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

     if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
     {
         qDebug() << "Mismatch of sets!";

         if (!missing_in_actual.isEmpty())
         {
             qDebug() << "Missing from the received result: " << missing_in_actual;
         }

         if (!unexpected_in_actual.isEmpty())
         {
             qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
         }
     }
      QCOMPARE(decriptions, expected_decriptions);
}
void test_decoding_message_from_Morse::test7_AMessageMadeUpOfMultipleSymbols_ASingleDotAndALongSequenceOfDashes()
{
    QString message_morse = ".----";
    QSet <QString> decriptions;
    decoding_message_from_Morse( message_morse, decriptions);

    QSet <QString> expected_decriptions ={ "ETTTT", "ATTT" ,"ETMT" ,"AMT", "ETO", "AO", "EMTT", "WTT", "EMM", "WM", "EOT", "JT", "1", "ETTM", "ATM" };

    QCOMPARE(decriptions.size(),expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty())
        {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty())
        {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }
 QCOMPARE(decriptions, expected_decriptions);
}
void test_decoding_message_from_Morse::test8_AMessageMadeUpOfMultipleSymbols_ASingleDashAndALongSequenceOfDots()
{
    QString message_morse = "-...";
    QSet <QString> decriptions;
    decoding_message_from_Morse( message_morse, decriptions);

    QSet <QString> expected_decriptions ={  "TEEE", "TEI" ,"TIE" ,"TS", "NEE", "NI", "DE", "B"  };

    QCOMPARE(decriptions.size(),expected_decriptions.size());
    QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
    QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

    if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
    {
        qDebug() << "Mismatch of sets!";

        if (!missing_in_actual.isEmpty())
        {
            qDebug() << "Missing from the received result: " << missing_in_actual;
        }

        if (!unexpected_in_actual.isEmpty())
        {
            qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
        }
    }
     QCOMPARE(decriptions, expected_decriptions);
}
 void test_decoding_message_from_Morse::test9_ASequenceOfIdenticalSymbols_Dot()
{
     QString message_morse = "....";
     QSet <QString> decriptions;
     decoding_message_from_Morse( message_morse, decriptions);

     QSet <QString> expected_decriptions ={ "EEEE", "EEI" ,"EIE" ,"ES", "IEE", "II", "SE", "H" };

     QCOMPARE(decriptions.size(),expected_decriptions.size());
     QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
     QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

     if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
     {
         qDebug() << "Mismatch of sets!";

         if (!missing_in_actual.isEmpty())
         {
             qDebug() << "Missing from the received result: " << missing_in_actual;
         }

         if (!unexpected_in_actual.isEmpty())
         {
             qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
         }
     }
 QCOMPARE(decriptions, expected_decriptions);
}
 void test_decoding_message_from_Morse::test10_ASequenceOfIdenticalSymbols_Dashes()
 {
     QString message_morse = "---";
     QSet <QString> decriptions;
     decoding_message_from_Morse( message_morse, decriptions);

     QSet <QString> expected_decriptions ={ "TTT", "TM", "MT", "O" };

     QCOMPARE(decriptions.size(),expected_decriptions.size());
     QSet<QString> missing_in_actual = expected_decriptions - decriptions; // Элементы, которые должны быть, но отсутствуют в фактическом результате
     QSet<QString> unexpected_in_actual = decriptions - expected_decriptions; // Элементы, которые есть в фактическом, но не должны быть

     if (!missing_in_actual.isEmpty() || !unexpected_in_actual.isEmpty())
     {
         qDebug() << "Mismatch of sets!";

         if (!missing_in_actual.isEmpty())
         {
             qDebug() << "Missing from the received result: " << missing_in_actual;
         }

         if (!unexpected_in_actual.isEmpty())
         {
             qDebug() << "Unexpected elements in the result: " << unexpected_in_actual;
         }
     }
      QCOMPARE(decriptions, expected_decriptions);
 }
