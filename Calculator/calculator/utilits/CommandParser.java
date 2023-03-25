package calculator.utilits;

import calculator.exception.parcer_exception.NoOperationException;
import calculator.exception.parcer_exception.ParcerException;
import calculator.exception.parcer_exception.ParcerNumberException;
import calculator.operations.Operation_IDs;

public class CommandParser {
    private static final String SPACE = " ";
    private static final int NONE = -1;

    public static Command parce(String str) throws ParcerException {
        int index = str.indexOf(SPACE);
        String commName;
        Operation_IDs commId;
        String[] args = {};

        if (index == NONE) {
            commName = str;
        } else {
            commName = str.substring(0, index);
        }

        try {
            commId = Operation_IDs.valueOf(commName);
        } catch (IllegalArgumentException e) {
            throw new ParcerException("parce command error ", new NoOperationException(commName));
        }

        if (commName.equals(Operation_IDs.PUSH.name())) {
            String value = str.substring(index + 1);
            if (value.contains(SPACE))
                throw new ParcerNumberException();
            args = new String[] { value };

        } else if (commName.equals(Operation_IDs.DEFINE.name())) {
            String variable, value;

            int index2 = str.indexOf(SPACE, index + 1);
            variable = str.substring(index + 1, index2);
            value = str.substring(index2 + 1);

            if (value.contains(SPACE))
                throw new ParcerNumberException();

            args = new String[] { variable, value };
        }

        return new Command(commId, args);
    }
}
