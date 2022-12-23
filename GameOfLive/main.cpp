#include "LiveSpace.h"
int main(int argc, char *argv[]) {

    liveSpace::InputParser cmdInput(argc, argv);
    liveSpace::Board myBoard(cmdInput);
    sf::RenderWindow window(sf::VideoMode(720, 720), cmdInput.returnUniName());

    sf::Clock clock;
    bool isPaused = true;
    int InputKeyCode;
    bool gameMod = cmdInput.return_game_mod();
    ll Base = liveSpace::Cage::returnBase();

    sf::Texture cageTextures;

    cageTextures.loadFromFile(liveSpace::tilesFileName);
    cageTextures.setSmooth(true);

    ll WEIGHT = myBoard.returnWeight(), HEIGHT = myBoard.returnHeight();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space)
                isPaused = !isPaused;
        }
        window.clear();
        vector <vector<liveSpace::Cage>> boardNow = myBoard.returnGameFieldPrev();

        drawing(HEIGHT,WEIGHT,cageTextures,Base,window,boardNow);

        float time = clock.getElapsedTime().asSeconds();

        if(updateCommand(isPaused,time,cmdInput,myBoard,window,gameMod,clock,InputKeyCode))
            break;

        window.display();
    }
    myBoard.outResult(cmdInput, cmdInput.returnOutput());
    return 0;
}

