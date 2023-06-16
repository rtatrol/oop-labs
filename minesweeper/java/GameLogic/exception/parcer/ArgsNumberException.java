package minesweeper.java.GameLogic.exception.parcer;

import minesweeper.java.GameLogic.utilits.Command;

public class ArgsNumberException extends ParcerException{
    public ArgsNumberException(Command.CommandIds id, int i){
        super(id.name() + " takes 2 arguments, got " + i);
    }
}