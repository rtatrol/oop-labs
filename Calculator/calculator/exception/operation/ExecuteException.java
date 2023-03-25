package calculator.exception.operation;

import calculator.operations.Operation_IDs;
import calculator.utilits.OperationUtils;

public class ExecuteException extends OperationException {
    public ExecuteException(Operation_IDs id, Throwable cause) {
        super("unable to execute " + OperationUtils.getNameById(id), cause);
    }

}
