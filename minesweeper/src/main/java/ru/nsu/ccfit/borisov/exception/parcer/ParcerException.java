package ru.nsu.ccfit.borisov.exception.parcer;

import ru.nsu.ccfit.borisov.exception.MinesweeperException;

public class ParcerException extends MinesweeperException {
    public ParcerException(String message, Throwable cause){
        super(message, cause);
    }
    public ParcerException(String message){
        super(message);
    }
    public ParcerException(){
        super();
    }
}