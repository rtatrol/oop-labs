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
            if (event.type == sf::Event::MouseButtonPressed and event.key.code == sf::Mouse::Left and
                cmdInput.ReturnIsStartMenu()) {

                sf::Vector2i MousePos = sf::Mouse::getPosition(window);
                if (liveSpace::Sample1Rect.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
                    cmdInput.isStartUpdate();
                    cmdInput.setInFile(liveSpace::InputSampleFile1);
                    cmdInput.setOutFile(liveSpace::OutputSampleFile1);
                    liveSpace::Board myBoard(cmdInput);
                }
                if (liveSpace::Sample2Rect.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
                    cmdInput.isStartUpdate();
                    cmdInput.setInFile(liveSpace::InputSampleFile2);
                    cmdInput.setOutFile(liveSpace::OutputSampleFile2);
                    cmdInput.UpdateUniverse();

                    myBoard.UpdateUniverse(cmdInput);
                }
            }
            if (event.type == sf::Event::MouseButtonPressed and event.key.code == sf::Mouse::Left and
                cmdInput.ReturnIsStartMenu()) {
                sf::Vector2i MousePos = sf::Mouse::getPosition(window);
                if (liveSpace::AuthorRect.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
                    cmdInput.isStartUpdate();
                    cmdInput.isAuthorUpdate();
                }
            }
            if (event.type == sf::Event::MouseButtonPressed and event.key.code == sf::Mouse::Left and
                cmdInput.ReturnIsAuthorMenu()) {
                sf::Vector2i MousePos = sf::Mouse::getPosition(window);
                if (liveSpace::ExitRect.getGlobalBounds().contains(MousePos.x, MousePos.y)) {
                    cmdInput.isStartUpdate();
                    cmdInput.isAuthorUpdate();
                }
            }
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

