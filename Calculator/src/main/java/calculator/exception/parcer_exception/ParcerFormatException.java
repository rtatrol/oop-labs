package calculator.exception.parcer_exception;

public class ParcerFormatException extends ParcerException{
    public ParcerFormatException(String s){
        super("Bad operation format "+s);
    }
}
