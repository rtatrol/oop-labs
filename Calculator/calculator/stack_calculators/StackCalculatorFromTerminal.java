package calculator.stack_calculators;

import java.util.Scanner;
import java.io.FileInputStream;

import calculator.Calculator;
import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.operations.Operation;
import calculator.utilits.Command;
import calculator.utilits.CommandParser;
import calculator.factory.FartoryOperations;

public class StackCalculatorFromTerminal implements Calculator {
    ProgramContext context;
    static final String configurationFileName = "Calculator/calculator/resources/configuration.txt";

    public StackCalculatorFromTerminal() throws CalculatorException {

        try {
            FileInputStream inputStream = new FileInputStream(configurationFileName);
            FartoryOperations.getResourcesAsStream(inputStream);
        } catch (Exception e) {
            throw new CalculatorException("Unable to configure calculator", e);
        }
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
            scanner.close();

        } catch (Exception e) {
            throw new CalculatorException("problems in line " + number_line, e);
        }
        return 0;
    }
}
