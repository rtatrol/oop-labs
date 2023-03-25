package calculator.utilits;

import calculator.operations.Operation_IDs;

public class Command {
    Operation_IDs id;
    String[] args;

    public Command(Operation_IDs id, String[] args) {
        this.args = args;
        this.id = id;
    }

    public Operation_IDs getId() {
        return id;
    }

    public String[] getArgs() {
        return args;
    }
}
