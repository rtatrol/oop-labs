package ru.nsu.ccfit.borisov.exception.game;

import ru.nsu.ccfit.borisov.exception.MinesweeperException;

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