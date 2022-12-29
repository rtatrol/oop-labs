#include "CSVParser.h"

using namespace std;
int main() {
    ifstream file("test.csv");

    CSVParser<int, string> parser(file, 0 /*skip first lines count*/);

    for (tuple<int, string> rs: parser)
    {
        cout << rs << endl;
    }

    return 0;
}