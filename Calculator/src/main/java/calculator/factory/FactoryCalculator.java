package calculator.factory;

import calculator.Calculator;
import calculator.exception.CalculatorException;
import calculator.stack_calculators.StackCalculatorFromFile;
import calculator.stack_calculators.StackCalculatorFromTerminal;

public class FactoryCalculator {
    public static Calculator Make(String[] args) throws CalculatorException{
        if(args==null)
        {
            throw new NullPointerException();
        }
        
        else if(args.length==0){
            return new StackCalculatorFromTerminal();
        }
        
        else if(args.length==1){
            return new StackCalculatorFromFile(args[1]);
        }
        else return null;
    }
}
