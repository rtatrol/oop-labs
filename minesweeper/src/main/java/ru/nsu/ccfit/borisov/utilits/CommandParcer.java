package ru.nsu.ccfit.borisov.utilits;

import ru.nsu.ccfit.borisov.exception.parcer.ArgsNumberException;
import ru.nsu.ccfit.borisov.exception.parcer.ParcerException;

public class CommandParcer {

    public static final String SPACE = " ";


    public static Command parsCommandLine(String str) throws ParcerException {
        String[] strSplit = str.split(SPACE);

        Command.CommandIds id = Command.CommandIds.valueOf(strSplit[0]);

        if (id.getArgsNum() != strSplit.length - 1) throw new ArgsNumberException(id, strSplit.length - 1);


        int[] args = new int[strSplit.length - 1];
        for (int i = 1; i < strSplit.length; i++) {
            args[i - 1] = Integer.parseInt(strSplit[i]);
        }
        return new Command(id, args);
    }
}