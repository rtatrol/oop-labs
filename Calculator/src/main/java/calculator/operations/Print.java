package calculator.operations;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.OperationException;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
public class Print implements Operation {
    static final Logger logger = LogManager.getLogger(Print.class.getName());
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        logger.info("executing operation");
        try{
            double result=context.peek();
            System.out.println(result);
        }
        catch(ContextException e){
            throw new ExecuteException(Operation_IDs.PRINT, e);
        }
        
    }
}
