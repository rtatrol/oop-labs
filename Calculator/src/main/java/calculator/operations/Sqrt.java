package calculator.operations;

import java.lang.Math;

import calculator.context.ProgramContext;
import calculator.exception.context_exceptions.ContextException;
import calculator.exception.operation.ExecuteException;
import calculator.exception.operation.NegativeSquareException;
import calculator.exception.operation.OperationException;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
public class Sqrt implements Operation {
    static final Logger logger = LogManager.getLogger(Sqrt.class.getName());
    @Override
    public void exec(ProgramContext context, String[] args) throws OperationException {
        logger.info("executing operation");
        try {
            double var=context.pop();
            if(var<0)throw new ExecuteException(OperationIds.SQRT, new NegativeSquareException());
            double result = Math.sqrt(var);
            context.push(result);
        } catch (ContextException e) {
            throw new ExecuteException(OperationIds.SQRT, e);
        }
    }
}
