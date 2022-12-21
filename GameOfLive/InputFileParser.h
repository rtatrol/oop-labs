#ifndef GAMEOFLIVE_INPUTFILEPARSER_H
#define GAMEOFLIVE_INPUTFILEPARSER_H

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
namespace liveSpace {
    class InputParser {

        bool gameMod;
        string InputFileName;
        ll iterations;
        ll helpIterations;
        string OutputFileName;
        string helpOutputFileName;

        string command;
        string universeName;
        pair<ll, ll> universeSize;
        pair<string, string> Rules;
        vector<pair<ll, ll>> cords;

    public:
        InputParser(int argc, char *argv[]);

        int commandUpdate();

        ll returnIterations();

        ll returnHelpIterations();

        string returnOutput();

        string returnHelpOutput();

        void subIterations(bool isHelp);

        pair<ll, ll> returnUniSize();

        pair<string, string> returnRules();

        ll returnCordsSize();

        vector<pair<ll, ll>> returnCordsVector();

        string returnUniName();

        void inputCommand(string newCommand);

        bool return_game_mod();
    };
}
#endif
