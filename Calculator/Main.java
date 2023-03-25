import calculator.Calculator;
import calculator.exception.CalculatorException;
import calculator.factory.FactoryCalculator;

public class Main {
    public static void main(String[] args) {
        try {
            Calculator calculator = FactoryCalculator.Make(args);
            assert calculator != null;
            calculator.do_Calculation();
        } catch (CalculatorException e) {
            e.printStackTrace();
        }
    }
}
