package minesweeper.java.Minesweeper.exception.game;

import minesweeper.java.Minesweeper.exception.MinesweeperException;

public class GameLogicException extends MinesweeperException {
    public GameLogicException() {
        super();
    }

    public GameLogicException(String message) {
        super(message);
    }

    public GameLogicException(String message, Throwable cause) {
        super(message, cause);
    }
}