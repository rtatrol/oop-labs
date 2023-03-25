package calculator.factory;

import calculator.operations.*;

public class FartoryOperations {
    public static Operation make(Operation_IDs id){
        return switch(id){
            case DEFINE -> new Define();
            case DIVISION -> new Division();
            case MULTIPLY -> new Multiply();
            case POP -> new Pop();
            case PRINT -> new Print();
            case PUSH -> new Push();
            case SQRT -> new Sqrt();
            case SUBTRACTION -> new Subtraction();
            case SUM -> new Sum();
            default -> null;
        };
    }
}
