package ru.nsu.ccfit.borisov.exception.field;

import ru.nsu.ccfit.borisov.exception.MinesweeperException;

public class FieldException extends MinesweeperException {
    public FieldException(String message, Throwable cause){
        super(message, cause);
    }
    public FieldException(String message){
        super(message);
    }
    public FieldException(){
        super();
    }
}