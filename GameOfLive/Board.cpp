#include "Board.h"

liveSpace::Board::Board(int num) {
    for (ll i = 0; i < num; ++i) {
        gameFieldPrev.emplace_back(vector<Cage>());
        for (ll l = 0; l < num; ++l) {
            bool testAlive = rand() % 2;
            Cage now(testAlive, l, i);
            gameFieldPrev[i].emplace_back(now);
        }
    }
}

liveSpace::Board::Board(InputParser &cmdInput) {
    pair<ll, ll> uniSize = cmdInput.returnUniSize();
    HEIGHT = uniSize.first + 1;
    WEIGHT = uniSize.second + 1;
    int keyZero='0';
    pair<string, string> Rules = cmdInput.returnRules();
    for (ll i = 0; i < Rules.first.size(); i++)
        Birth.insert(Rules.first[i] - '0');

    for (ll i = 0; i < Rules.second.size(); i++)
        Survival.insert(Rules.second[i] - keyZero);

    const std::string imagesFile="images/UpdateTiles.png";
    cageTextures.loadFromFile(imagesFile);
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

    vector<pair<ll, ll>> cords = cmdInput.returnCordsVector();
    for (ll i = 0; i < cmdInput.returnCordsSize(); i++) {
        Cage now(1, cords[i].first, cords[i].second);
        gameFieldPrev[cords[i].second][cords[i].first] = now;
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

ll liveSpace::Board::scoreAround(ll x, ll y) {
    ll result = 0;
    for (ll i = y - 1; i <= y + 1; i++)
        for (ll l = x - 1; l <= x + 1; l++)
            if (gameFieldPrev[i][l].returnAlive())result++;

    if (gameFieldPrev[y][x].returnAlive())result--;
    return result;
}

bool liveSpace::Board::checkAliveAndSur(ll x, ll y, ll scoreThis) {
    return (gameFieldNext[y][x].returnAlive() and Survival.find(scoreThis) == Survival.end());
}

bool liveSpace::Board::checkDeathAndBorn(ll x, ll y, ll scoreThis) {
    return (!gameFieldNext[y][x].returnAlive() and Birth.find(scoreThis) != Birth.end());
}

void liveSpace::Board::update() {
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

void liveSpace::Board::outResult(InputParser &cmdInput, string file) {
    ofstream fOut;
    fOut.open(file);
    fOut << cmdInput.returnUniName() << "\n";
    fOut << cmdInput.returnUniSize().first << ' ' << cmdInput.returnUniSize().second << "\n";
    fOut << cmdInput.returnRules().first << ' ' << cmdInput.returnRules().second << "\n";
    for (ll i = 1; i < HEIGHT - 1; i++)
        for (ll l = 1; l < WEIGHT - 1; l++) {
            if (gameFieldPrev[i][l].returnAlive())
                fOut << i << ' ' << l << "\n";
        }
    fOut.close();
}

void liveSpace::Board::gameMod1(InputParser &cmdInput, int &InputKeyCode) {
    while (!cmdInput.returnHelpIterations()) {
        string nowCommand;
        cin >> nowCommand;
        cmdInput.inputCommand(nowCommand);
        InputKeyCode = cmdInput.commandUpdate();
        if (InputKeyCode == 1)
            this->outResult(cmdInput, cmdInput.returnHelpOutput());
        if (InputKeyCode == 3) {
            this->outResult(cmdInput, cmdInput.returnOutput());
            exit(0);
        }
    }
    cmdInput.subIterations(true);
}

ll liveSpace::Board::returnHeight() {
    return HEIGHT;
}

ll liveSpace::Board::returnWeight() {
    return WEIGHT;
}

vector<vector<liveSpace::Cage>> liveSpace::Board::returnGameFieldPrev() {
    return gameFieldPrev;
}