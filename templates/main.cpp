#include "CSVParser.h"

int main() {
    std::ifstream file("testBase.txt");//Or testUp.txt

    CSVParser<int, std::string,double> parser(file, 0);
    //parser.setSeparators(',',';','\n');
    for (std::tuple<int, std::string,double> rs: parser)
        std::cout << rs << std::endl;

    return 0;
}