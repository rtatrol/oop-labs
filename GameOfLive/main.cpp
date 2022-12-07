#include "Objects.h"

int main(int argc, char *argv[]) {
    InputParser cmdInput(argc, argv);
    Board myBoard(cmdInput);
    sf::RenderWindow window(sf::VideoMode(720, 720), cmdInput.returnUniName());

    Clock clock;
    bool isPaused = true;
    int InputKeyCode;
    bool gameMod = cmdInput.return_game_mod();
    ll Base = Cage::returnBase();

    Texture cageTextures;
    cageTextures.loadFromFile("images/UpdateTiles.png");
    cageTextures.setSmooth(true);

    ll WEIGHT = myBoard.returnWeight(), HEIGHT = myBoard.returnHeight();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed and event.key.code == Keyboard::Space)
                isPaused = !isPaused;
        }

        window.clear();

        vector <vector<Cage>> boardNow = myBoard.returnGameFieldPrev();

        for (ll i = 1; i < HEIGHT - 1; i++) {
            for (ll l = 1; l < WEIGHT - 1; l++) {
                Sprite toDraw;
                toDraw.setTexture(cageTextures);
                if (i % (HEIGHT - 1) == 0 or l % (WEIGHT - 1) == 0)
                    toDraw.setTextureRect(IntRect(0, 0, Base, Base));
                else
                    toDraw.setTextureRect(IntRect(boardNow[i][l].getSpriteNumb() * Base, 0, Base, Base));
                toDraw.setPosition((l - 1) * Base, (i - 1) * Base);
                window.draw(toDraw);
            }
        }

        float time = clock.getElapsedTime().asSeconds();
        if (time >= 0.2 and !isPaused) {

            if (!cmdInput.returnIterations()) {
                window.close();
                break;
            }
            cmdInput.subIterations(false);

            if (gameMod)
                myBoard.gameMod1(cmdInput, InputKeyCode);

            clock.restart();
            myBoard.update();
        }
        window.display();
    }
    myBoard.outResult(cmdInput, cmdInput.returnOutput());
    return 0;
}

