package calculator.context;

import calculator.exception.context_exceptions.PopException;
import calculator.exception.context_exceptions.PeekException;

import java.util.Stack;
import java.util.HashMap;

public class ProgramContext {
    private final Stack<Double> stack;
    private final HashMap<String, Double> variables;

    public ProgramContext() {
        stack = new Stack<Double>();
        variables = new HashMap<String, Double>();
    }

    public void push(Double var) {
        stack.push(var);
    }

    public double pop() throws PopException {
        if (stack.isEmpty())
            throw new PopException("stack is empty\n");
        return stack.pop();
    }

    public double peek()throws PeekException {
        if (stack.isEmpty())
            throw new PeekException("stack is empty\n");
        return stack.peek();
    }

    public boolean containsVariable(String var) {
        return variables.containsKey(var);
    }

    public double getVariableValue(String var) {
        return variables.get(var);
    }

    public void putVariableValue(String variable, double value) {
        variables.put(variable, value);
    }
}
