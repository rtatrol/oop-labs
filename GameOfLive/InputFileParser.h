#ifndef GAMEOFLIVE_INPUTFILEPARSER_H
#define GAMEOFLIVE_INPUTFILEPARSER_H

#include <bits/stdc++.h>

typedef long long ll;
namespace liveSpace {
    class InputParser {

        bool gameMod;
        bool IsStartMenu;
        bool IsAuthorMenu;
        std::string InputFileName;
        ll iterations;
        ll helpIterations;
        std::string OutputFileName;
        std::string helpOutputFileName;

        std::string command;
        std::string universeName;
        std::pair<ll, ll> universeSize;
        std::pair<std::string, std::string> Rules;
        std::vector<std::pair<ll, ll>> cords;

    public:
        InputParser(int argc, char *argv[]);

        bool ReturnIsStartMenu();

        bool ReturnIsAuthorMenu();

        void UpdateUniverse();

        void isStartUpdate();

        void isAuthorUpdate();

        void setInFile(std::string str);

        void setOutFile(std::string str);

        int commandUpdate();

        ll returnIterations();

        ll returnHelpIterations();

        std::string returnOutput();

        std::string returnHelpOutput();

        void subIterations(bool isHelp);

        std::pair<ll, ll> returnUniSize();

        std::pair<std::string, std::string> returnRules();

        ll returnCordsSize();

        std::vector<std::pair<ll, ll>> returnCordsVector();

        std::string returnUniName();

        void inputCommand(std::string newCommand);

        bool return_game_mod();
    };
}
#endif
