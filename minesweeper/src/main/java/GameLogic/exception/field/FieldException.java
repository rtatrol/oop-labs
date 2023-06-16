package GameLogic.exception.field;

import GameLogic.exception.MinesweeperException;

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