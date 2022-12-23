#include "InputFileParser.h"

namespace allConst
{
    const bool ConsoleStart = 1;
    const int FileNameCount = 1;
    const int IterationsCount = 3;

    const int DefaultIter = 25;
    int ResultDump=1;
    int ResultTick=2;
    int ResultExit=3;
    int ResultHelp=4;

    const std::string TickCommand = "tick";
    const std::string DumpCommand = "dump";
    const std::string ExitCommand = "exit";
    const std::string HelpCommand = "help";
    std::string InputSampleFile="input/sample2.txt";
    std::string OutputSampleFile="output/sample2Solve.txt";
}

liveSpace::InputParser::InputParser(int argc, char *argv[]) {

    helpIterations = 1;
    const int OutCount = argc - 1;

    helpOutputFileName = "";
    if (argc == 1) {
        gameMod = !allConst::ConsoleStart;
        InputFileName = allConst::InputSampleFile;
        OutputFileName = allConst::OutputSampleFile;
        iterations = allConst::DefaultIter;
    } else {
        gameMod = allConst::ConsoleStart;
        InputFileName = argv[allConst::FileNameCount];
        iterations = atoi(argv[allConst::IterationsCount]);
        OutputFileName = argv[OutCount];
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

    if (command == allConst::DumpCommand) {
        cin >> helpOutputFileName;
        return allConst::ResultDump;
    }
    if (command == allConst::TickCommand) {
        cin >> helpIterations;
        return allConst::ResultTick;
    }
    if (command == allConst::ExitCommand)
        return allConst::ResultExit;
    if (command == allConst::HelpCommand) {
        cout << "\n\ndump <filename> - save universe in file\n";
        cout << "tick count 'i' iterations\n";
        cout << "exit - close game\n";
        cout << "help - print command manual\n\n\n";
        return allConst::ResultHelp;
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