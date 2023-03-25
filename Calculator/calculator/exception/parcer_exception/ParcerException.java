package calculator.exception.parcer_exception;

import calculator.exception.CalculatorException;

public class ParcerException extends CalculatorException {
    public ParcerException() {
        super();
    }

    public ParcerException(String s) {
        super(s);
    }

    public ParcerException(String s, Throwable cause) {
        super(s, cause);
    }
}
