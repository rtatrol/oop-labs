package calculator.stack_calculators;

import java.io.FileInputStream;
import java.util.Scanner;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import calculator.Calculator;
import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.factory.FactoryOperations;
import calculator.operations.Operation;
import calculator.utilits.Command;
import calculator.utilits.CommandParser;

public class StackCalculatorFromTerminal implements Calculator {
    ProgramContext context;
    static final Logger logger = LogManager.getLogger(StackCalculatorFromTerminal.class.getName());
    static final String configurationFileName = "Calculator/configuration.txt";

    public StackCalculatorFromTerminal() throws CalculatorException {
        logger.info("initializing calculator data");
        try {
            FileInputStream inputStream = new FileInputStream(configurationFileName);
            FactoryOperations.getResourcesAsStream(inputStream);
        } catch (Exception e) {
            throw new CalculatorException("Unable to configure calculator", e);
        }
        context = new ProgramContext();
    }

    @Override
    public double calculate() throws CalculatorException {
        int number_line = 1;
        logger.info("start calculation");
        try {
            logger.info("read line");
            Scanner scanner = new Scanner(System.in);
            String line = scanner.nextLine();

            while (line != null && !line.equals("exit")) {
                Command command = CommandParser.parce(line);
                Operation op = FactoryOperations.make(command.getId());

                op.exec(context, command.getArgs());

                logger.info("read line");
                line = scanner.nextLine();
                number_line++;
            }
            logger.info("finishing the calculations");

            scanner.close();

        } catch (Exception e) {
            logger.error("error in " + number_line + " line");
            throw new CalculatorException("problems in line " + number_line, e);
        }
        return 0;
    }
}
