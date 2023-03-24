#include "InputFileParser.h"

namespace allConst {
    const bool ConsoleStart = 1;
    const int FileNameCount = 1;
    const int IterationsCount = 3;

    const int DefaultIter = 25;
    int ResultDump = 1;
    int ResultTick = 2;
    int ResultExit = 3;
    int ResultHelp = 4;
    bool IsStartMenu = true;
    bool IsAuthorMenu = false;

    const std::string TickCommand = "tick";
    const std::string DumpCommand = "dump";
    const std::string ExitCommand = "exit";
    const std::string HelpCommand = "help";
    std::string InputSampleFile = "input/sample1.txt";
    std::string OutputSampleFile = "output/sample1Solve.txt";
}

bool liveSpace::InputParser::ReturnIsStartMenu() {
    return IsStartMenu;
}

bool liveSpace::InputParser::ReturnIsAuthorMenu() {
    return IsAuthorMenu;
}

void liveSpace::InputParser::isStartUpdate() {
    this->IsStartMenu = !this->IsStartMenu;
}

void liveSpace::InputParser::isAuthorUpdate() {
    this->IsAuthorMenu = !this->IsAuthorMenu;
}

void liveSpace::InputParser::setInFile(std::string str) {
    InputFileName = str;
}

void liveSpace::InputParser::setOutFile(std::string str) {
    OutputFileName = str;
}

liveSpace::InputParser::InputParser(int argc, char *argv[]) {

    helpIterations = 1;
    const int OutCount = argc - 1;

    helpOutputFileName = "";
    if (argc == 1) {
        IsStartMenu = allConst::IsStartMenu;
        IsAuthorMenu = allConst::IsAuthorMenu;
        gameMod = !allConst::ConsoleStart;
        InputFileName = allConst::InputSampleFile;
        OutputFileName = allConst::OutputSampleFile;
        iterations = allConst::DefaultIter;
    } else {
        IsStartMenu = !allConst::IsStartMenu;
        IsAuthorMenu = allConst::IsAuthorMenu;
        gameMod = allConst::ConsoleStart;
        InputFileName = argv[allConst::FileNameCount];
        iterations = atoi(argv[allConst::IterationsCount]);
        OutputFileName = argv[OutCount];
    }
    std::ifstream fin;
    fin.open(InputFileName);
    if (!fin.is_open()) {
        std::cout << "You are not right in filename";
        return;
    }

    fin >> universeName;

    fin >> universeSize.first;
    fin >> universeSize.second;

    fin >> Rules.first;
    fin >> Rules.second;

    while (!fin.eof()) {
        std::pair<ll, ll> now;
        fin >> now.second >> now.first;
        cords.push_back(now);
    }
}

void liveSpace::InputParser::UpdateUniverse() {
    std::ifstream fin;
    fin.open(InputFileName);
    if (!fin.is_open()) {
        std::cout << "You are not right in filename";
        return;
    }

    fin >> universeName;

    fin >> universeSize.first;
    fin >> universeSize.second;

    fin >> Rules.first;
    fin >> Rules.second;
    cords.clear();
    while (!fin.eof()) {
        std::pair<ll, ll> now;
        fin >> now.second >> now.first;
        cords.push_back(now);
    }
}

int liveSpace::InputParser::commandUpdate() {

    if (command == allConst::DumpCommand) {
        std::cin >> helpOutputFileName;
        return allConst::ResultDump;
    }
    if (command == allConst::TickCommand) {
        std::cin >> helpIterations;
        return allConst::ResultTick;
    }
    if (command == allConst::ExitCommand)
        return allConst::ResultExit;
    if (command == allConst::HelpCommand) {
        std::cout << "\n\ndump <filename> - save universe in file\n";
        std::cout << "tick count 'i' iterations\n";
        std::cout << "exit - close game\n";
        std::cout << "help - print command manual\n\n\n";
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

std::string liveSpace::InputParser::returnOutput() {
    return OutputFileName;
}

std::string liveSpace::InputParser::returnHelpOutput() {
    return helpOutputFileName;
}

void liveSpace::InputParser::subIterations(bool isHelp) {
    isHelp == true ? this->helpIterations-- : this->iterations--;
}

std::pair<ll, ll> liveSpace::InputParser::returnUniSize() {
    return universeSize;
}

std::pair<std::string, std::string> liveSpace::InputParser::returnRules() {
    return Rules;
}

ll liveSpace::InputParser::returnCordsSize() {
    return cords.size();
}

std::vector<std::pair<ll, ll>> liveSpace::InputParser::returnCordsVector() {
    return cords;
}

std::string liveSpace::InputParser::returnUniName() {
    return universeName;
}

void liveSpace::InputParser::inputCommand(std::string newCommand) {
    command = newCommand;
}

bool liveSpace::InputParser::return_game_mod() {
    return gameMod;
}