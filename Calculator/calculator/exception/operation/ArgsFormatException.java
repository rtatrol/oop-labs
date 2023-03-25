package calculator.exception.operation;

public class ArgsFormatException extends OperationException {
    public ArgsFormatException(Class<?> class1){
        super("error at class type, must be "+ class1.getName());
    }
}
