package calculator.factory;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;

import calculator.exception.CalculatorException;
import calculator.operations.*;

public class FactoryOperations {

    private static final String SPACE = " ";
    static HashMap<OperationIds, Class<?>> idClassHashMap=new HashMap<>();

    public static void getResourcesAsStream(InputStream stream) throws CalculatorException,IOException {
        InputStreamReader streamReader = new InputStreamReader(stream);
        BufferedReader reader = new BufferedReader(streamReader);
        String line;
        try {
            for (int i = 0; i < OperationIds.values().length; i++) {
                line = reader.readLine();
                String[] lineSplit = line.split(SPACE);
                if (lineSplit.length != 2)
                    throw new CalculatorException("Bad configuration file format");
                idClassHashMap.put(OperationIds.valueOf(lineSplit[0]), Class.forName(lineSplit[1]));
            }
            reader.close();
            streamReader.close();
        } catch (ClassNotFoundException e) {
            throw new CalculatorException("wrong operation class",e);
        }
    }

    public static Operation make(OperationIds id) throws CalculatorException {
        try {
            return switch (id) {
                case DEFINE -> (Operation) idClassHashMap.get(OperationIds.DEFINE).newInstance();
                case DIVISION -> (Operation) idClassHashMap.get(OperationIds.DIVISION).newInstance();
                case MULTIPLY -> (Operation) idClassHashMap.get(OperationIds.MULTIPLY).newInstance();
                case POP -> (Operation) idClassHashMap.get(OperationIds.POP).newInstance();
                case PRINT -> (Operation) idClassHashMap.get(OperationIds.PRINT).newInstance();
                case PUSH -> (Operation) idClassHashMap.get(OperationIds.PUSH).newInstance();
                case SQRT -> (Operation) idClassHashMap.get(OperationIds.SQRT).newInstance();
                case SUBTRACTION -> (Operation) idClassHashMap.get(OperationIds.SUBTRACTION).newInstance();
                case SUM -> (Operation) idClassHashMap.get(OperationIds.SUM).newInstance();
                default -> null;
            };
        } catch (Exception e) {
            throw new CalculatorException("cant make operation object ",e);
        }
    }
}
