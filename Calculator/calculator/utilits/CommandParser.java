package calculator.utilits;

import calculator.exception.parcer_exception.ParcerException;
import calculator.exception.parcer_exception.ParcerFormatException;
import calculator.exception.parcer_exception.ParcerNumberException;
import calculator.operations.Operation_IDs;

public class CommandParser {
    private static final String SPACE = " ";
    private static final int NONE = -1;

    public static Command parce(String str) throws ParcerException {
        int index = str.indexOf(SPACE);
        if (index == NONE) {
            if (!OperationUtils.isOperationName(str))
                throw new ParcerFormatException(str);
            return new Command(OperationUtils.getIdByName(str), null);
        }

        String command = str.substring(0, index);

        if (!OperationUtils.isOperationName(command))
            throw new ParcerFormatException(str);

        if (command.equals(OperationUtils.getNameById(Operation_IDs.PUSH))) {
            String value = str.substring(index + 1);
            if (value.contains(SPACE))
                throw new ParcerNumberException();
            String[] args = { value };
            return new Command(Operation_IDs.PUSH, args);

        } else if (command.equals(OperationUtils.getNameById(Operation_IDs.DEFINE))) {
            String variable, value;

            int index2 = str.indexOf(SPACE, index + 1);
            variable = str.substring(index + 1, index2);
            value = str.substring(index2 + 1);

            if (value.contains(SPACE))
                throw new ParcerNumberException();

            String args[] = { variable, value };
            return new Command(Operation_IDs.DEFINE, args);
        }
        throw null;
    }
}
