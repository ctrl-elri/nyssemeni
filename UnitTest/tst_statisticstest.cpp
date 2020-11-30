#include <QtTest>

// add necessary includes here

class statisticsTest : public QObject
{
    Q_OBJECT

public:
    statisticsTest();
    ~statisticsTest();

private slots:
    void test_case1();

    void testPoints();

};

statisticsTest::statisticsTest()
{

}

statisticsTest::~statisticsTest()
{

}

void statisticsTest::test_case1()
{

}

void statisticsTest::testPoints()
{

}



QTEST_APPLESS_MAIN(statisticsTest)

#include "tst_statisticstest.moc"
