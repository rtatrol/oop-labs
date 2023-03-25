package calculator.exception.parcer_exception;

public class NoOperationException extends ParcerException{
    public NoOperationException(String s){
        super("operation exception"+s);
    }
}
