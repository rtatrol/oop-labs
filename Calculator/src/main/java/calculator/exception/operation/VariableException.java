package calculator.exception.operation;

public class VariableException extends OperationException{
    public VariableException(String name){
        super("error variable with name "+name+'\n');
    }
}
