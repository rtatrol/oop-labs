#ifndef GAMEOFLIVE_OBJECTS_H
#define GAMEOFLIVE_OBJECTS_H

#include "SFML/Graphics.hpp"
#include "InputFileParser.h"

using namespace sf;

class Cage {
public:
    static const ll Base = 30;
    bool isAlive;
    ll spriteNumber;
    Vector2f Position;

    Cage(ll num, ll x, ll y) {
        isAlive = num;
        spriteNumber = num;
        Position.x = x * Base;
        Position.y = y * Base;
    }

    void update() {
        isAlive = !isAlive;
        if (isAlive)
            spriteNumber = rand() % 3 + 1;
        else
            spriteNumber = 0;
    }

    void kill() {
        isAlive = false;
        spriteNumber = 0;
    }
};

class Board {
public:
    int WEIGHT, HEIGHT;

    set<ll> Birth, Survival;

    vector<vector<Cage>> gameFieldPrev;
    vector<vector<Cage>> gameFieldNext;

    Texture cageTextures;

    Board(int num) {
        for (ll i = 0; i < num; ++i) {
            gameFieldPrev.emplace_back(vector<Cage>());
            for (ll l = 0; l < num; ++l) {
                bool testAlive = rand() % 2;
                Cage now(testAlive, l, i);
                gameFieldPrev[i].emplace_back(now);
            }
        }
    }


    Board(inputParser &cmdInput) {
        HEIGHT = cmdInput.universeSize.first + 1;
        WEIGHT = cmdInput.universeSize.second + 1;

        for (ll i = 0; i < cmdInput.Rules.first.size(); i++)
            Birth.insert(cmdInput.Rules.first[i] - '0');

        for (ll i = 0; i < cmdInput.Rules.second.size(); i++)
            Survival.insert(cmdInput.Rules.second[i] - '0');

        cageTextures.loadFromFile("images/UpdateTiles.png");
        cageTextures.setSmooth(true);

        for (ll i = 0; i < HEIGHT; i++) {
            gameFieldPrev.emplace_back(vector<Cage>());
            for (ll l = 0; l < WEIGHT; l++) {
                Cage now(0, l, i);
                gameFieldPrev[i].emplace_back(now);
            }
        }

        gameFieldPrev[0][0].kill();
        gameFieldPrev[0][WEIGHT - 1].kill();
        gameFieldPrev[HEIGHT - 1][0].kill();
        gameFieldPrev[HEIGHT - 1][WEIGHT - 1].kill();

        for (ll i = 0; i < cmdInput.cords.size(); i++) {
            Cage now(1, cmdInput.cords[i].first, cmdInput.cords[i].second);
            gameFieldPrev[cmdInput.cords[i].second][cmdInput.cords[i].first] = now;
        }

        for (ll i = 1; i < HEIGHT - 1; i++) {
            gameFieldPrev[i][0] = gameFieldPrev[i][WEIGHT - 2];
            gameFieldPrev[i][WEIGHT - 1] = gameFieldPrev[i][1];
        }
        for (ll i = 1; i < WEIGHT - 1; i++) {
            gameFieldPrev[0][i] = gameFieldPrev[HEIGHT - 2][i];
            gameFieldPrev[HEIGHT - 1][i] = gameFieldPrev[1][i];
        }
    }

    ll scoreAround(ll x, ll y) {
        ll result = 0;
        for (ll i = y - 1; i <= y + 1; i++)
            for (ll l = x - 1; l <= x + 1; l++)
                if (gameFieldPrev[i][l].isAlive)result++;

        if (gameFieldPrev[y][x].isAlive)result--;
        return result;
    }

    bool checkAliveAndSur(ll x, ll y, ll scoreThis) {
        return (gameFieldNext[y][x].isAlive and Survival.find(scoreThis) == Survival.end());
    }

    bool checkDeathAndBorn(ll x, ll y, ll scoreThis) {
        return (!gameFieldNext[y][x].isAlive and Birth.find(scoreThis) != Birth.end());
    }

    void update() {
        gameFieldNext = gameFieldPrev;
        for (ll i = 1; i < HEIGHT - 1; i++) {
            for (ll l = 1; l < WEIGHT - 1; l++) {
                ll scoreThis = scoreAround(l, i);
                if (checkAliveAndSur(l, i, scoreThis) or checkDeathAndBorn(l, i, scoreThis))
                    gameFieldNext[i][l].update();
            }
        }

        for (ll i = 1; i < HEIGHT - 1; i++) {
            gameFieldNext[i][0] = gameFieldNext[i][WEIGHT - 2];
            gameFieldNext[i][WEIGHT - 1] = gameFieldNext[i][1];
        }
        for (ll i = 1; i < WEIGHT - 1; i++) {
            gameFieldNext[0][i] = gameFieldNext[HEIGHT - 2][i];
            gameFieldNext[HEIGHT - 1][i] = gameFieldNext[1][i];
        }
        gameFieldPrev = gameFieldNext;
    }

    void outResult(inputParser &cmdInput, string file) {
        ofstream fOut;
        fOut.open(file);
        fOut << cmdInput.universeName << "\n";
        fOut << cmdInput.universeSize.first << ' ' << cmdInput.universeSize.second << "\n";
        fOut << cmdInput.Rules.first << ' ' << cmdInput.Rules.second << "\n";
        for (ll i = 1; i < HEIGHT - 1; i++)
            for (ll l = 1; l < WEIGHT - 1; l++) {
                if (gameFieldPrev[i][l].isAlive)
                    fOut << i << ' ' << l << "\n";
            }
        fOut.close();
    }

    void gameMod1(inputParser &cmdInput, int &InputKeyCode) {
        if (!cmdInput.iterations)
            return;
        cmdInput.iterations--;

        while (!cmdInput.helpIterations) {
            cin >> cmdInput.command;
            InputKeyCode = cmdInput.commandUpdate();
            if (InputKeyCode == 1)
                this->outResult(cmdInput, cmdInput.helpOutputFileName);
            if (InputKeyCode == 3) {
                this->outResult(cmdInput, cmdInput.OutputFileName);
                exit(0);
            }
        }
        cmdInput.helpIterations--;
    }
};

#endif
