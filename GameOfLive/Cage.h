//
// Created by boris on 14.12.2022.
//

#ifndef GAMEOFLIVE_TEST_CAGE_H
#define GAMEOFLIVE_TEST_CAGE_H
#include <bits/stdc++.h>
#include "SFML/Graphics.hpp"

typedef long long ll;
namespace liveSpace {
    class Cage {
        static const ll Base = 30;
        bool isAlive;
        ll spriteNumber;
        sf::Vector2f Position;

    public:
        Cage(ll num, ll x, ll y);

        void update();

        void kill();

        bool returnAlive();

        static const ll returnBase();

        ll getSpriteNumb();
    };
}
#endif //GAMEOFLIVE_TEST_CAGE_H
