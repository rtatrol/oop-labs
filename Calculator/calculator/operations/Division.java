package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.DivisionByZero;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;



public class Division implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try{
            double var1=context.pop();
            double var2=context.pop();
            if(var2==0)throw new ExecuteException(Operation_IDs.DIVISION, new DivisionByZero());

            double result = var1/var2;
            context.push(result);
        }catch(ContextException e){
            throw new ExecuteException(Operation_IDs.DIVISION, e);
        }
    }
}
