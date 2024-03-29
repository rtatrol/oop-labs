package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.DivisionByZero;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Division implements Operation {
    static final Logger logger = LogManager.getLogger(Division.class.getName());
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        logger.info("executing operation");
        try{
            double var1=context.pop();
            double var2=context.pop();
            if(var2==0)throw new ExecuteException(OperationIds.DIVISION, new DivisionByZero());

            double result = var1/var2;
            context.push(result);
        }catch(ContextException e){
            throw new ExecuteException(OperationIds.DIVISION, e);
        }
    }
}
