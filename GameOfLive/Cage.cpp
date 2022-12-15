//
// Created by boris on 14.12.2022.
//
#include "Cage.h"

Cage::Cage(ll num, ll x, ll y) {
    isAlive = num;
    spriteNumber = num;
    Position.x = x * Base;
    Position.y = y * Base;
}

void Cage::update() {
    isAlive = !isAlive;
    if (isAlive)
        spriteNumber = rand() % 3 + 1;
    else
        spriteNumber = 0;
}

void Cage::kill() {
    isAlive = false;
    spriteNumber = 0;
}

bool Cage::returnAlive() {
    return isAlive;
}

const ll Cage::returnBase() {
    return Base;
}

ll Cage::getSpriteNumb() {
    return spriteNumber;
}
