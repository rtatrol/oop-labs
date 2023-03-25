package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.operation.ArgsNumberException;
import calculator.exception.operation.OperationException;
import calculator.exception.operation.VariableException;
import calculator.utilits.ParametrUtils;

public class Push implements Operation {
    public static final int VARIABLE_STR = 0;

    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        if (args.length != 1)
            throw new ArgsNumberException();
        else if (ParametrUtils.isValue(args[VARIABLE_STR]))
            context.push(Double.parseDouble(args[VARIABLE_STR]));
        else if (context.containsVariable(args[VARIABLE_STR])) {
            context.push(context.getVariableValue(args[VARIABLE_STR]));
        } else
            throw new VariableException(args[VARIABLE_STR]);
    }

}
