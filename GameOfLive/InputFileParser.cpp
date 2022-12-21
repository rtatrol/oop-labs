#include "InputFileParser.h"

liveSpace::InputParser::InputParser(int argc, char *argv[]) {
    const bool consoleStart = 1;
    helpIterations = 1;
    const int fileNameCount = 1;
    const int iterationsCount = 3;
    const int outCount = argc - 1;
    const int defaultIter = 25;
    std::string inputSampleFile="input/sample2.txt",outputSampleFile="output/sample2Solve.txt";
    helpOutputFileName = "";
    if (argc == 1) {
        gameMod = !consoleStart;
        InputFileName = inputSampleFile;
        OutputFileName = outputSampleFile;
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

int liveSpace::InputParser::commandUpdate() {
    const std::string TickCommand = "tick";
    const std::string DumpCommand = "dump";
    const std::string ExitCommand = "exit";
    const std::string HelpCommand = "help";

    int resultDump=1;
    int resultTick=2;
    int resultExit=3;
    int resultHelp=4;

    if (command == DumpCommand) {
        cin >> helpOutputFileName;
        return resultDump;
    }
    if (command == TickCommand) {
        cin >> helpIterations;
        return resultTick;
    }
    if (command == ExitCommand)
        return resultExit;
    if (command == HelpCommand) {
        cout << "\n\ndump <filename> - save universe in file\n";
        cout << "tick count 'i' iterations\n";
        cout << "exit - close game\n";
        cout << "help - print command manual\n\n\n";
        return resultHelp;
    }
    return 0;
}

ll liveSpace::InputParser::returnIterations() {
    return iterations;
}

ll liveSpace::InputParser::returnHelpIterations() {
    return helpIterations;
}

string liveSpace::InputParser::returnOutput() {
    return OutputFileName;
}

string liveSpace::InputParser::returnHelpOutput() {
    return helpOutputFileName;
}

void liveSpace::InputParser::subIterations(bool isHelp) {
    isHelp == true ? this->helpIterations-- : this->iterations--;
}

pair<ll, ll> liveSpace::InputParser::returnUniSize() {
    return universeSize;
}

pair<string, string> liveSpace::InputParser::returnRules() {
    return Rules;
}

ll liveSpace::InputParser::returnCordsSize() {
    return cords.size();
}

vector<pair<ll, ll>> liveSpace::InputParser::returnCordsVector() {
    return cords;
}

string liveSpace::InputParser::returnUniName() {
    return universeName;
}

void liveSpace::InputParser::inputCommand(string newCommand) {
    command = newCommand;
}

bool liveSpace::InputParser::return_game_mod() {
    return gameMod;
}