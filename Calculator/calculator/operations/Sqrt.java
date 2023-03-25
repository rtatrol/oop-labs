package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.NegativeSquareException;
import calculator.exception.operation.OperationException;

import java.lang.Math;

public class Sqrt implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try {
            double var=context.pop();
            if(var<0)throw new ExecuteException(Operation_IDs.SQRT, new NegativeSquareException());
            double result = Math.sqrt(var);
            context.push(result);
        } catch (ContextException e) {
            throw new ExecuteException(Operation_IDs.SQRT, e);
        }
    }
}
