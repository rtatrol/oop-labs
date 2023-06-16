package minesweeper.java.GameLogic.gui;

import minesweeper.java.GameLogic.GameLogic;

public class Context {
    private final MyWin win;


    private final GameLogic game;
    private boolean isClick = true;

    private boolean needToRestart = false;

    public Context(GameLogic game, MyWin win){
        this.game = game;
        this.win = win;
    }

    public boolean isClick() {
        return isClick;
    }

    public void setClick(boolean click) {
        isClick = click;
    }

    public GameLogic getGame() {
        return game;
    }

    public boolean isNeedToRestart() {
        return needToRestart;
    }

    public void setNeedToRestart(boolean needToRestart) {
        this.needToRestart = needToRestart;
    }

    public MyWin getWin() {
        return win;
    }
}
