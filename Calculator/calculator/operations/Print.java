package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;

public class Print implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try{
            double result=context.peek();
            System.out.println(result);
        }
        catch(ContextException e){
            throw new ExecuteException(Operation_IDs.PRINT, e);
        }
        
    }
}
