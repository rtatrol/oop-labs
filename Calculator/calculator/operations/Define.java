package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.operation.OperationException;
import calculator.exception.operation.ArgsFormatException;
import calculator.exception.operation.ArgsNumberException;
import calculator.utilits.ParametrUtils;

public class Define implements Operation {
    public static final int VARIABLE_STR = 0;
    public static final int VARIABLE_VALUE = 1;

    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        if (args.length != 2)
            throw new ArgsNumberException();
        else if (ParametrUtils.isValue(args[VARIABLE_STR]))
            throw new ArgsFormatException(String.class);
        else if (!ParametrUtils.isValue(args[VARIABLE_VALUE]))
            throw new ArgsFormatException(Number.class);
        context.putVariableValue(args[VARIABLE_STR], Double.parseDouble(args[VARIABLE_VALUE]));
    }

}
