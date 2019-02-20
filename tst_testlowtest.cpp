#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "../Army.cpp"
#include "../Troop.cpp"
#include "../Greyjoy.cpp"
#include "../Stark.cpp"
#include "../Baratheon.cpp"
#include "../Lannister.cpp"
#include "../WhiteWalkers.cpp"
#include "../Targaryen.cpp"
#include "../Territory.cpp"
#include "../Map.cpp"
#include "../AbstractArmyFactory.cpp"
#include "../ConcreteArmyFactory.cpp"


class TestLoWTest : public QObject
{
    Q_OBJECT

public:
    TestLoWTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCase1();

    void test_Greyjoy_getName();
    void test_Territory_isEarth();
    void test_ConcreteArmyFactory_createArmy();
    void test_Map_conquer();
    void test_Army_randomStrategy();
};

TestLoWTest::TestLoWTest()
{
}

void TestLoWTest::initTestCase()
{
}

void TestLoWTest::cleanupTestCase()
{
}

void TestLoWTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestLoWTest::test_Greyjoy_getName()
{
    string name = "Greyjoy";
    Greyjoy g(0,0,0,0);
    QCOMPARE(g.getName(), name);
}

void TestLoWTest::test_Territory_isEarth()
{
    Territory t;
    QCOMPARE(t.isEarth(), true);
}

void TestLoWTest::test_Map_conquer()
{
    Map mappa;
    bool esito;
    float powerInvader = mappa.readTerritory(0, 1).getArmy()->getPower();
    float powerDefender = mappa.readTerritory(0, 2).getArmy()->getPower();
    bool hasAttacked = mappa.conquer(0,1,0,2, esito);
    if(hasAttacked)
    {
        QCOMPARE(mappa.readTerritory(0,1).getArmy()->getPower(), powerInvader);
    }
    else
    {
        QCOMPARE(mappa.readTerritory(0,2).getArmy()->getPower(), powerDefender);
    }
}

void TestLoWTest::test_Army_randomStrategy()
{
    bool oS;
    bool oM;
    bool less;
    int i = 0;
    while (!(oS && oM && less)) {
        i++;
        Strategy randomStrategy;

        randomStrategy = Army::randomStrategy();

        switch (randomStrategy)
        {
            case Strategy::onlySimple:
                oS = true;
            case Strategy::lessDefense:
                less = true;
            case Strategy::onlyMagic:
                oM = true;
        }
        if(i > 100)
            break;
    }
    QVERIFY(oS && oM && less);

}

void TestLoWTest::test_ConcreteArmyFactory_createArmy()
{
    string name = "Greyjoy";
    Map mappa;
    ConcreteArmyFactory g("Greyjoy");
    mappa.writeTerritory(0,0, Territory(g.createArmy()));
    QCOMPARE(mappa.readTerritory(0,0).getArmy()->getName(), name);
}

QTEST_MAIN(TestLoWTest)

#include "tst_testlowtest.moc"
