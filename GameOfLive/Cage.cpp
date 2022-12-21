//
// Created by boris on 14.12.2022.
//
#include "Cage.h"

liveSpace::Cage::Cage(ll num, ll x, ll y) {
    isAlive = num;
    spriteNumber = num;
    Position.x = x * Base;
    Position.y = y * Base;
}

void liveSpace::Cage::update() {
    isAlive = !isAlive;
    if (isAlive)
        spriteNumber = rand() % 3 + 1;
    else
        spriteNumber = 0;
}

void liveSpace::Cage::kill() {
    isAlive = false;
    spriteNumber = 0;
}

bool liveSpace::Cage::returnAlive() {
    return isAlive;
}

const ll liveSpace::Cage::returnBase() {
    return Base;
}

ll liveSpace::Cage::getSpriteNumb() {
    return spriteNumber;
}
