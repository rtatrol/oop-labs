package calculator.exception.parcer_exception;

public class NoOperationException extends ParcerException{
    public NoOperationException(String s){
        super("Not exist such operation "+s);
    }
}
