package minesweeper.java.GameLogic.gui;

import minesweeper.java.GameLogic.GameLogic;

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
