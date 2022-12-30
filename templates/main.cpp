#include "CSVParser.h"

using namespace outOperator;
int main() {
    std::ifstream file("testBase.txt");//Or testUp.txt

    CSVPars::CSVParser<int, std::string,double> parser(file, 0);
    for (std::tuple<int, std::string,double> rs: parser)
        std::cout<< rs << std::endl;

    return 0;
}