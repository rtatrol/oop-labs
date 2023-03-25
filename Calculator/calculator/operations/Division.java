package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;



public class Division implements Operation {
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        try{
            double result = context.pop()/context.pop();
            context.push(result);
        }catch(CalculatorException e){
            throw new ExecuteException(Operation_IDs.DIVISION, e);
        }
    }
}
