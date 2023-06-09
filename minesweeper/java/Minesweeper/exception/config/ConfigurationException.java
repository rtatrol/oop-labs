package minesweeper.java.Minesweeper.exception.config;

import minesweeper.java.Minesweeper.exception.MinesweeperException;

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