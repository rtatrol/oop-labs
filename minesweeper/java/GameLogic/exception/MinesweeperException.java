package minesweeper.java.GameLogic.exception;

public class MinesweeperException extends Exception{
   
    public MinesweeperException(){
        super();
    }
    public MinesweeperException(String message, Throwable cause){
        super(message, cause);
    }
    public MinesweeperException(String message){
        super(message);
    }
}