#include "InputFileParser.h"

InputParser::InputParser(int argc, char *argv[]) {
    const bool consoleStart = 1;
    helpIterations = 1;
    const int fileNameCount = 1;
    const int iterationsCount = 3;
    const int outCount = argc - 1;
    const int defaultIter = 15;
    helpOutputFileName = "";
    if (argc == 1) {
        gameMod = !consoleStart;
        InputFileName = "input/sample2.txt";
        OutputFileName = "output/sample2Solve.txt";
        iterations = defaultIter;
    } else {
        gameMod = consoleStart;
        InputFileName = argv[fileNameCount];
        iterations = atoi(argv[iterationsCount]);
        OutputFileName = argv[outCount];
    }
    ifstream fin;
    fin.open(InputFileName);
    if (!fin.is_open()) {
        cout << "You are not right in filename";
        return;
    }

    fin >> universeName;

    fin >> universeSize.first;
    fin >> universeSize.second;

    fin >> Rules.first;
    fin >> Rules.second;

    while (!fin.eof()) {
        pair<ll, ll> now;
        fin >> now.second >> now.first;
        cords.push_back(now);
    }
}

int InputParser::commandUpdate() {
    const std::string TickCommand = "tick";
    const std::string DumpCommand = "dump";
    const std::string ExitCommand = "exit";
    const std::string HelpCommand = "help";

    if (command == DumpCommand) {
        cin >> helpOutputFileName;
        return 1;
    }
    if (command == TickCommand) {
        cin >> helpIterations;
        return 2;
    }
    if (command == ExitCommand)
        return 3;
    if (command == HelpCommand) {
        cout << "\n\ndump <filename> - save universe in file\n";
        cout << "tick count 'i' iterations\n";
        cout << "exit - close game\n";
        cout << "help - print command manual\n\n\n";
        return 4;
    }
    return 0;
}

ll InputParser::returnIterations() {
    return iterations;
}

ll InputParser::returnHelpIterations() {
    return helpIterations;
}

string InputParser::returnOutput() {
    return OutputFileName;
}

string InputParser::returnHelpOutput() {
    return helpOutputFileName;
}

void InputParser::subIterations(bool isHelp) {
    isHelp == true ? this->helpIterations-- : this->iterations--;
}

pair<ll, ll> InputParser::returnUniSize() {
    return universeSize;
}

pair<string, string> InputParser::returnRules() {
    return Rules;
}

ll InputParser::returnCordsSize() {
    return cords.size();
}

vector<pair<ll, ll>> InputParser::returnCordsVector() {
    return cords;
}

string InputParser::returnUniName() {
    return universeName;
}

void InputParser::inputCommand(string newCommand) {
    command = newCommand;
}

bool InputParser::return_game_mod() {
    return gameMod;
}
