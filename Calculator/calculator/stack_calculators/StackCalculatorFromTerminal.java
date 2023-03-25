package calculator.stack_calculators;

import java.util.Scanner;

import calculator.Calculator;
import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.operations.Operation;
import calculator.operations.Operation_IDs;
import calculator.utilits.Command;
import calculator.utilits.CommandParser;
import calculator.factory.FartoryOperations;

public class StackCalculatorFromTerminal implements Calculator {
    ProgramContext context;

    public StackCalculatorFromTerminal() {
        context = new ProgramContext();
    }
    
    @Override
    public double do_Calculation() throws CalculatorException {
        int number_line = 1;
        try {
            Scanner scanner = new Scanner(System.in);
            String line = scanner.nextLine();

            while (line != null && !line.equals("exit")) {
                Command command = CommandParser.parce(line);
                Operation op = FartoryOperations.make(command.getId());

                op.exec(context, command.getArgs());

                line = scanner.nextLine();
                number_line++;
            }

        } catch (Exception e) {
            throw new CalculatorException("problems in line " + number_line, e);
        }
        return 0;
    }
}
