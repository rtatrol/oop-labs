#ifndef GAMEOFLIVE_TEST_LIVESPACE_H
#define GAMEOFLIVE_TEST_LIVESPACE_H

#include "Cage.h"
#include "Board.h"
#include "InputFileParser.h"

namespace liveSpace {
    const std::string InputSampleFile1 = "input/sample1.txt";
    const std::string OutputSampleFile1 = "output/sample1Solve.txt";
    const std::string InputSampleFile2 = "input/sample2.txt";
    const std::string OutputSampleFile2 = "output/sample2Solve.txt";

    const std::string tilesFileName = "images/UpdateTiles.png";
    const std::string ImageStartMenu = "images/StartMenu.png";
    const std::string ImageAuthorMenu = "images/AuthorMenu.png";
    sf::RectangleShape Sample1Rect(sf::Vector2f(250, 100));
    const sf::Vector2f Sample1RectCords(210, 107);
    sf::RectangleShape Sample2Rect(sf::Vector2f(250, 100));
    const sf::Vector2f Sample2RectCords(203, 260);
    sf::RectangleShape AuthorRect(sf::Vector2f(250, 100));
    const sf::Vector2f AuthorRectCords(200, 460);
    sf::RectangleShape ExitRect(sf::Vector2f(340, 100));
    const sf::Vector2f ExitRectCords(187, 500);

    void drawing(ll HEIGHT, ll WEIGHT, sf::Texture cageTextures, ll Base,
                 sf::RenderWindow &window, std::vector<std::vector<liveSpace::Cage>> boardNow) {
        for (ll i = 1; i < HEIGHT - 1; i++) {
            for (ll l = 1; l < WEIGHT - 1; l++) {
                sf::Sprite toDraw;
                toDraw.setTexture(cageTextures);
                if (i % (HEIGHT - 1) == 0 or l % (WEIGHT - 1) == 0)
                    toDraw.setTextureRect(sf::IntRect(0, 0, Base, Base));
                else
                    toDraw.setTextureRect(sf::IntRect(boardNow[i][l].getSpriteNumb() * Base, 0, Base, Base));
                toDraw.setPosition((l - 1) * Base, (i - 1) * Base);
                window.draw(toDraw);
            }
        }
    }

    bool updateCommand(bool isPaused, float time, liveSpace::InputParser &cmdInput,
                       liveSpace::Board &myBoard, sf::RenderWindow &window, bool gameMod, sf::Clock &clock,
                       int InputKeyCode) {
        bool isBreak = false;
        if (time >= 0.2 and !isPaused) {
            if (!cmdInput.returnIterations()) {
                window.close();
                isBreak = true;
            }
            cmdInput.subIterations(false);

            if (gameMod)
                myBoard.gameMod1(cmdInput, InputKeyCode);

            clock.restart();
            myBoard.update();
        }
        return isBreak;
    }
}
#endif //GAMEOFLIVE_TEST_LIVESPACE_H
