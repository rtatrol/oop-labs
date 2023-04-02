package calculator.stack_calculators;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;

import calculator.Calculator;
import calculator.context.ProgramContext;
import calculator.exception.CalculatorException;
import calculator.factory.FactoryOperations;
import calculator.operations.Operation;
import calculator.utilits.Command;
import calculator.utilits.CommandParser;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class StackCalculatorFromFile implements Calculator {
    String filename;
    ProgramContext context;
    static final Logger logger = LogManager.getLogger(StackCalculatorFromFile.class.getName());
    static final String configurationFileName = "Calculator/configuration.txt";

    public StackCalculatorFromFile(String name) throws CalculatorException {
        logger.info("initializing calculator data");
        try {
            FileInputStream inputStream = new FileInputStream(configurationFileName);
            FactoryOperations.getResourcesAsStream(inputStream);
        } catch (Exception e) {
            throw new CalculatorException("Unable to configure calculator", e);
        }

        if (name == null)
            throw new NullPointerException();

        context = new ProgramContext();
        this.filename = name;
    }

    @Override
    public double calculate() throws CalculatorException {
        int number_line = 1;
        logger.info("start calculation from " + filename);
        try {

            FileReader fileReader = new FileReader(filename);
            BufferedReader reader = new BufferedReader(fileReader);
            logger.info("read line");
            String line = reader.readLine();

            while (line != null) {
                Command command = CommandParser.parce(line);
                Operation op = FactoryOperations.make(command.getId());
                op.exec(context, command.getArgs());

                logger.info("read line");
                line = reader.readLine();
                number_line++;
            }
            logger.info("finishing the calculations");
            reader.close();
            fileReader.close();

        } catch (IOException e) {
            logger.error("unable to read " + filename);
            throw new CalculatorException("cant read file", e);
        } catch (Exception e) {
            logger.error("error in " + number_line + " line: " + e.getLocalizedMessage());
            throw new CalculatorException("problems in line" + number_line, e);
        }

        return 0;
    }
}
