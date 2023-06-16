package calculator.utilits;

import calculator.operations.OperationIds;

public class Command {
    OperationIds id;
    String[] args;

    public Command(OperationIds id, String[] args) {
        this.args = args;
        this.id = id;
    }

    public OperationIds getId() {
        return id;
    }

    public String[] getArgs() {
        return args;
    }
}
