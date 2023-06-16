package ru.nsu.ccfit.borisov.exception.field;

import ru.nsu.ccfit.borisov.config.Configuration;

public class IndexOutOfBoundException extends FieldException {

    public IndexOutOfBoundException(int i, int j, Configuration configuration){
        super("("+i+", "+j+") out of bound. Field size is "+ configuration.getLineLength() + "x "+configuration.getColumnLength());
    }
}