package calculatorTest;

import calculator.exception.CalculatorException;
import calculator.factory.FactoryException;
import calculator.factory.*;
import calculator.operations.*;
import calculator.stack_calculators.*;

import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

import static org.assertj.core.api.Assertions.assertThat;

@DisplayName("Factory's tests")
public class FactoryTest {

    @Test
    @DisplayName("Operation factory test")
    void FactoryOperationsTest() throws CalculatorException, IOException {
        try{
        FileInputStream in = new FileInputStream("src/main/resources/configuration.txt");
        calculator.factory.FactoryOperations.getResourcesAsStream(in);
        in.close();
    
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.DEFINE)).isInstanceOf(Define.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.DIVISION)).isInstanceOf(Division.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.MULTIPLY)).isInstanceOf(Multiply.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.POP)).isInstanceOf(Pop.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.PRINT)).isInstanceOf(Print.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.PUSH)).isInstanceOf(Push.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.SQRT)).isInstanceOf(Sqrt.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.SUBTRACTION)).isInstanceOf(Subtraction.class);
        assertThat(calculator.factory.FactoryOperations.make(OperationIds.SUM)).isInstanceOf(Sum.class);
        }
        catch(CalculatorException e){
            throw new CalculatorException("test error",e);
        }
    }
}