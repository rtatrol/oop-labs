package minesweeper.java.Minesweeper.exception.field;

import minesweeper.java.Minesweeper.config.Configuration;

public class IndexOutOfBoundException extends FieldException {

    public IndexOutOfBoundException(int i, int j, Configuration configuration){
        super("("+i+", "+j+") out of bound. Field size is "+ configuration.getLineLength() + "x "+configuration.getColumnLength());
    }
}