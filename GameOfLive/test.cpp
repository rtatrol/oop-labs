#include "LiveSpace.h"

#include "googletest-main/googletest/include/gtest/gtest.h"

TEST(TestScore, test1) {
    ll size = 3;
    liveSpace::Board testBoard(size);
    vector<vector<liveSpace::Cage>> boardNow = testBoard.returnGameFieldPrev();
    ll result = 0;
    for (ll i = 0; i <= 2; i++)
        for (ll l = 0; l <= 2; l++)
            if (boardNow[i][l].returnAlive())result++;

    if (boardNow[1][1].returnAlive())result--;

    EXPECT_TRUE(result == testBoard.scoreAround(1, 1));
}

TEST(TestAlive, test1) {
    liveSpace::Cage testCage1(1, 0, 0);
    liveSpace::Cage testCage0(0, 0, 0);
    testCage1.kill();
    EXPECT_TRUE(testCage1.returnAlive() == testCage0.returnAlive());
}

TEST(TestSample1, test1) {
    liveSpace::InputParser testPars(1, NULL);
    liveSpace::Board testBoard(testPars);
    for (int i = 0; i < testPars.returnIterations(); ++i)
        testBoard.update();
    testBoard.outResult(testPars, "output/Sample1Solve.txt");
    ifstream correctAnswer, programAnswer;
    correctAnswer.open("output/TestSample1Solved.txt");
    programAnswer.open("output/Sample1Solved.txt");

    string cor = "", ans = "";
    bool isTrue = 1;
    while (getline(programAnswer, ans) and getline(correctAnswer, cor))
        isTrue *= (ans == cor);
    EXPECT_TRUE(isTrue);
}

TEST(TestSample2,test1)
{
    ifstream correctAnswer, programAnswer;
    correctAnswer.open("output/TestSample2Solved.txt");
    programAnswer.open("output/Sample2Solved.txt");
    string cor = "", ans = "";
    bool isTrue = 1;
    while (getline(programAnswer, ans) and getline(correctAnswer, cor))
        isTrue *= (ans == cor);
    EXPECT_TRUE(isTrue);
}