#ifndef GAMEOFLIVE_OBJECTS_H
#define GAMEOFLIVE_OBJECTS_H

#include "SFML/Graphics.hpp"
#include "InputFileParser.h"

using namespace sf;

class Cage {
    static const ll Base = 30;
    bool isAlive;
    ll spriteNumber;
    Vector2f Position;

public:
    Cage(ll num, ll x, ll y);

    void update();

    void kill();

    bool returnAlive();

    static const ll returnBase();

    ll getSpriteNumb();
};

class Board {

    int WEIGHT, HEIGHT;

    set<ll> Birth, Survival;

    vector<vector<Cage>> gameFieldPrev;
    vector<vector<Cage>> gameFieldNext;

    Texture cageTextures;

public:
    Board(int num);

    Board(InputParser &cmdInput);

    ll scoreAround(ll x, ll y);

    bool checkAliveAndSur(ll x, ll y, ll scoreThis);

    bool checkDeathAndBorn(ll x, ll y, ll scoreThis);

    void update();

    void outResult(InputParser &cmdInput, string file);

    void gameMod1(InputParser &cmdInput, int &InputKeyCode);

    ll returnWeight();

    ll returnHeight();

    vector<vector<Cage>> returnGameFieldPrev();
};

#endif
