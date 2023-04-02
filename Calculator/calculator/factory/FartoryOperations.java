package calculator.factory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;

import calculator.exception.CalculatorException;
import calculator.operations.*;

public class FartoryOperations {

    private static final String SPACE = " ";
    static HashMap<Operation_IDs, Class<?>> idClassHashMap;

    static {
        idClassHashMap = new HashMap<>();
    }

    public static void getResourcesAsStream(InputStream stream) throws CalculatorException,IOException {
        InputStreamReader streamReader = new InputStreamReader(stream);
        BufferedReader reader = new BufferedReader(streamReader);
        String line;
        try {
            for (int i = 0; i < Operation_IDs.values().length; i++) {
                line = reader.readLine();
                String[] lineSplit = line.split(SPACE);
                if (lineSplit.length != 2)
                    throw new CalculatorException("Bad configuration file format");
                idClassHashMap.put(Operation_IDs.valueOf(lineSplit[0]), Class.forName(lineSplit[1]));
            }
            reader.close();
            streamReader.close();
        } catch (ClassNotFoundException e) {
            throw new CalculatorException("wrong operation class",e);
        }
    }

    public static Operation make(Operation_IDs id) throws CalculatorException {
        try {
            return switch (id) {
                case DEFINE -> (Operation) idClassHashMap.get(Operation_IDs.DEFINE).newInstance();
                case DIVISION -> (Operation) idClassHashMap.get(Operation_IDs.DIVISION).newInstance();
                case MULTIPLY -> (Operation) idClassHashMap.get(Operation_IDs.MULTIPLY).newInstance();
                case POP -> (Operation) idClassHashMap.get(Operation_IDs.POP).newInstance();
                case PRINT -> (Operation) idClassHashMap.get(Operation_IDs.PRINT).newInstance();
                case PUSH -> (Operation) idClassHashMap.get(Operation_IDs.PUSH).newInstance();
                case SQRT -> (Operation) idClassHashMap.get(Operation_IDs.SQRT).newInstance();
                case SUBTRACTION -> (Operation) idClassHashMap.get(Operation_IDs.SUBTRACTION).newInstance();
                case SUM -> (Operation) idClassHashMap.get(Operation_IDs.SUM).newInstance();
                default -> null;
            };
        } catch (Exception e) {
            throw new CalculatorException("cant make operation object ",e);
        }
    }
}
