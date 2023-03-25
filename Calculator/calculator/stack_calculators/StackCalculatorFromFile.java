package calculator.stack_calculators;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import calculator.Calculator;
import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.operations.Operation;
import calculator.utilits.Command;
import calculator.utilits.CommandParser;
import calculator.factory.FartoryOperations;

public class StackCalculatorFromFile implements Calculator {
    String filename;
    ProgramContext context;

    public StackCalculatorFromFile(String name) {
        if (name == null)
            throw new NullPointerException();

        context = new ProgramContext();
        filename = name;
    }

    @Override
    public double do_Calculation() throws CalculatorException {
        int number_line = 1;
        try {

            FileReader fileReader = new FileReader(filename);
            BufferedReader reader = new BufferedReader(fileReader);
            String line = reader.readLine();
            
            while (line != null) {
                Command command = CommandParser.parce(line);
                Operation op = FartoryOperations.make(command.getId());
                op.exec(context, command.getArgs());

                line = reader.readLine();
                number_line++;
            }
            reader.close();
            fileReader.close();

        } catch (IOException e) {
            throw new CalculatorException("cant read file", e);
        } catch (Exception e) {
            throw new CalculatorException("problems in line" + number_line, e);
        }

        return 0;
    }
}
