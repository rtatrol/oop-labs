#include "Objects.h"

#include "gtest.h"

TEST(TestScore, test1) {
    ll size = 3;
    Board testBoard(size);

    ll result = 0;
    for (ll i = 0; i <= 2; i++)
        for (ll l = 0; l <= 2; l++)
            if (testBoard.gameFieldPrev[i][l].isAlive)result++;

    if (testBoard.gameFieldPrev[1][1].isAlive)result--;

    EXPECT_TRUE(result == testBoard.scoreAround(1, 1));
}

TEST(TestAlive,test1){
    Cage testCage1(1,0,0);
    Cage testCage0(0,0,0);
    testCage1.kill();
    EXPECT_TRUE(testCage1.isAlive==testCage0.isAlive);
}


//int main(int argc,char *argv[])
//{
//    setlocale(LC_ALL,"Rus");
//    inputParser cmdInput(argc,argv);
//    Board myBoard(cmdInput);
//    int windowHeight=(myBoard.HEIGHT-1)*Cage::Base,windowWeight=(myBoard.WEIGHT-1)*Cage::Base;
//    windowHeight=min(930,windowHeight);
//    windowWeight=min(1110,windowWeight);
//
//    sf::RenderWindow window(sf::VideoMode(windowWeight,windowHeight),cmdInput.universeName);
//
//    Clock clock;
//    bool isPaused=true;
//    int InputKeyCode;
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//            if(event.type==Event::KeyPressed and event.key.code==Keyboard::Space)
//                isPaused=!isPaused;
//        }
//
//        window.clear();
//
//        for(ll i=1;i<myBoard.HEIGHT-1;i++)
//        {
//            for(ll l=1;l<myBoard.WEIGHT-1;l++)
//            {
//                Sprite toDraw;
//                toDraw.setTexture(myBoard.cageTextures);
//                if(i%(myBoard.HEIGHT-1)==0 or l%(myBoard.WEIGHT-1)==0)toDraw.setTextureRect(IntRect(0,0,Cage::Base,Cage::Base));
//                else
//                toDraw.setTextureRect(IntRect(myBoard.gameFieldPrev[i][l].spriteNumber*Cage::Base,0,Cage::Base,Cage::Base));
//
//                toDraw.setPosition((l-1)*Cage::Base,(i-1)*Cage::Base);
//                window.draw(toDraw);
//            }
//        }
//
//        float time=clock.getElapsedTime().asSeconds();
//        if(time>=0.2 and !isPaused)
//        {
//            if(cmdInput.gameMod)
//               myBoard.gameMod1(cmdInput,InputKeyCode);
//            clock.restart();
//            myBoard.update();
//        }
//        window.display();
//    }
//    myBoard.outResult(cmdInput,cmdInput.OutputFileName);
//    return 0;
//}
//
