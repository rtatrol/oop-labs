package ru.nsu.ccfit.borisov.exception.parcer;

import ru.nsu.ccfit.borisov.utilits.Command;

public class ArgsNumberException extends ParcerException{
    public ArgsNumberException(Command.CommandIds id, int i){
        super(id.name() + " takes 2 arguments, got " + i);
    }
}