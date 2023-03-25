package calculator.exception.context_exceptions;

import calculator.exception.CalculatorException;

public class PeekException extends CalculatorException {
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
