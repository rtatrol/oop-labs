#include "LiveSpace.h"

int main(int argc, char *argv[]) {

    liveSpace::InputParser cmdInput(argc, argv);
    liveSpace::Board myBoard(cmdInput);
    sf::RenderWindow window(sf::VideoMode(720, 720), "game");

    sf::Clock clock;
    bool isPaused = true;
    int InputKeyCode;
    bool gameMod = cmdInput.return_game_mod();
    ll Base = liveSpace::Cage::returnBase();

    sf::Texture cageTextures, StartTextures, AuthorTextures;
    sf::Sprite StartSprite, AuthorSprite;

    cageTextures.loadFromFile(liveSpace::tilesFileName);
    StartTextures.loadFromFile(liveSpace::ImageStartMenu);
    AuthorTextures.loadFromFile(liveSpace::ImageAuthorMenu);

    StartSprite.setTexture(StartTextures);
    AuthorSprite.setTexture(AuthorTextures);

    liveSpace::Sample1Rect.setPosition(liveSpace::Sample1RectCords);
    liveSpace::Sample2Rect.setPosition(liveSpace::Sample2RectCords);
    liveSpace::AuthorRect.setPosition(liveSpace::AuthorRectCords);
    liveSpace::ExitRect.setPosition(liveSpace::ExitRectCords);

    ll WEIGHT = myBoard.returnWeight(), HEIGHT = myBoard.returnHeight();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space)
                isPaused = !isPaused;

            liveSpace::ChooseSample(cmdInput, window, event, myBoard);
            liveSpace::IsAuthorOpen(event, cmdInput, window);
            liveSpace::IsAuthorLeave(event, cmdInput, window);
        }
        window.clear();

        if (cmdInput.ReturnIsStartMenu()) {
            window.draw(StartSprite);
        }
        if (cmdInput.ReturnIsAuthorMenu()) {
            window.draw(AuthorSprite);
        }
        if (!cmdInput.ReturnIsStartMenu() and !cmdInput.ReturnIsAuthorMenu()) {
            std::vector<std::vector<liveSpace::Cage>> boardNow = myBoard.returnGameFieldPrev();

            drawing(HEIGHT, WEIGHT, cageTextures, Base, window, boardNow);

            float time = clock.getElapsedTime().asSeconds();

            if (updateCommand(isPaused, time, cmdInput, myBoard, window, gameMod, clock, InputKeyCode))
                break;
        }

        window.display();
    }
    myBoard.outResult(cmdInput, cmdInput.returnOutput());
    return 0;
}

