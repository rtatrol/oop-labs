#include "CSVParser.h"
#include "googletest-main/googletest/include/gtest/gtest.h"
using namespace outOperator;

TEST(Sample1,test1)
{
    std::ifstream file("testBase.txt");
    std::ifstream answer("NoAnswerBase.txt");

    CSVPars::CSVParser<int, std::string,double> parser(file, 0);
    bool res=true;
    for (std::tuple<int, std::string,double> rs: parser) {
        std::string bufAnswer="",bufRs="";
        answer>>bufAnswer;
        bufRs=std::get<0>(rs);
        res*=(bufAnswer==bufRs);
    }
    EXPECT_FALSE(res);
}

TEST(Sample2,test1)
{
    std::ifstream file("testUp.txt");
    std::ifstream answer("NoAnswerUp.txt");

    CSVPars::CSVParser<int, std::string> parser(file, 0);
    parser.setSeparators(',',';','\n');

    bool res=true;
    for (std::tuple<int, std::string> rs: parser) {
        std::string bufAnswer="",bufRs="";
        answer>>bufAnswer;
        bufRs=std::get<0>(rs);
        res*=(bufAnswer==bufRs);
    }
    EXPECT_FALSE(res);
}