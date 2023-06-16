package GameLogic.exception.parcer;

import GameLogic.exception.MinesweeperException;

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