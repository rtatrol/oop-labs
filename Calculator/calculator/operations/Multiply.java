package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.operation.OperationException;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;

public class Multiply implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try {
            double result = context.pop() * context.pop();
            context.push(result);
        } catch (ContextException e) {
            throw new ExecuteException(Operation_IDs.MULTIPLY, e);
        }

    }
}
