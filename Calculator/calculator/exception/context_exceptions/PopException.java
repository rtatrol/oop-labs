package calculator.exception.context_exceptions;

import calculator.exception.CalculatorException;

public class PopException extends CalculatorException {
    public PopException() {
        super();
    }

    public PopException(String s) {
        super(s);
    }

    public PopException(String s, Throwable cause) {
        super(s, cause);
    }
}
