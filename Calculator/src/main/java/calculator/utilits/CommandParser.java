package calculator.utilits;

import calculator.exception.parcer_exception.NoOperationException;
import calculator.exception.parcer_exception.ParcerException;
import calculator.exception.parcer_exception.ParcerNumberException;
import calculator.operations.OperationIds;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class CommandParser {
    private static final String SPACE = " ";
    private static final int NONE = -1;
    static Logger logger = LogManager.getLogger(CommandParser.class.getName());

    public static Command parce(String str) throws ParcerException {
        logger.info("parsing line");
        int index = str.indexOf(SPACE);
        String commName;
        OperationIds commId;
        String[] args = {};

        if (index == NONE) {
            commName = str;
        } else {
            commName = str.substring(0, index);
        }

        try {
            commId = OperationIds.valueOf(commName);
        } catch (IllegalArgumentException e) {
            throw new ParcerException("parce command error ", new NoOperationException(commName));
        }

        if (commName.equals(OperationIds.PUSH.name())) {
            String value = str.substring(index + 1);
            if (value.contains(SPACE))
                throw new ParcerNumberException();
            args = new String[] { value };

        } else if (commName.equals(OperationIds.DEFINE.name())) {
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
