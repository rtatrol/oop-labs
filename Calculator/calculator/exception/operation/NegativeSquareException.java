package calculator.exception.operation;


public class NegativeSquareException extends OperationException{
    public NegativeSquareException(){
        super("Negative value in square");
    }
}
