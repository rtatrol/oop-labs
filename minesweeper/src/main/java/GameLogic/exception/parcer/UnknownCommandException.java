package GameLogic.exception.parcer;

public class UnknownCommandException extends ParcerException{

    public UnknownCommandException(String name){
        super("unknown command: "+name);
    }
}