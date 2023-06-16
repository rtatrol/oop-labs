package minesweeper.java.GameLogic.exception.config;

import minesweeper.java.GameLogic.exception.MinesweeperException;

public class ConfigurationException extends MinesweeperException {
    
    public ConfigurationException(){
        super();
    }
    public ConfigurationException(String message){
        super(message);
    }
    public ConfigurationException(String message, Throwable cause){
        super(message, cause);
    }
}