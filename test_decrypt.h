#ifndef TEST_DECRYPT_H
#define TEST_DECRYPT_H
#include <QString>
#include <QSet>
#include <QObject>
#include <QTest>  // Обязательно для QCOMPARE

class test_decrypt : public QObject
{
    Q_OBJECT
public:
    explicit test_decrypt(QObject *parent = nullptr);

private slots:
    void testBasic();
    void testTheMessageConsistsTwoLines();
    void testMessageConsistsOfTwoDots();
    void testMessageConsistsOfTwoHyphens();
    void testMessageConsistsOfADot();
    void testMessageConsistsOfAHyphen();
    void testMultiCharacterMessage();
    void CharactersAlphabetDecipheredTheSameWay();
    void testPartOfMessageAlreadyHasTranslation();
    void testTheListOfExistingTransfersIsNotEmpty();
    void ThereIsNoTranslationSymbolInTheAlphabet();

signals:
};

#endif // TEST_DECRYPT_H
