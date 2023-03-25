package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;

public class Subtraction implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try {
            double result = context.pop() - context.pop();
            context.push(result);
        } catch (ContextException e) {
            throw new ExecuteException(Operation_IDs.SUBTRACTION, e);
        }
    }
}
