package calculator.exception.context_exceptions;
public class PeekException extends ContextException {
    public PeekException() {
        super();
    }

    public PeekException(String s) {
        super(s);
    }

    public PeekException(String s, Throwable cause) {
        super(s, cause);
    }
}
