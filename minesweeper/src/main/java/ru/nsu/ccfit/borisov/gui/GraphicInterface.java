package ru.nsu.ccfit.borisov.gui;

import ru.nsu.ccfit.borisov.GameLogic;

public class GraphicInterface {
    private GameLogic game;
    private MyWin Win;
    public GraphicInterface() {
        game = new GameLogic();
        Win = new MyWin(game);
    }

    public void startGame(){
        Win.setVisible(true);
    }
}
