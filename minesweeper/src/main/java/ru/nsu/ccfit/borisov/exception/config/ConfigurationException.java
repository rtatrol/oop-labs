package ru.nsu.ccfit.borisov.exception.config;

import ru.nsu.ccfit.borisov.exception.MinesweeperException;

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