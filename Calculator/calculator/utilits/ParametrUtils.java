package calculator.utilits;

public class ParametrUtils {
    public static boolean isValue(String var) {
        if (var == null) {
            return false;
        }
        try {
            double result = Double.parseDouble(var);
        } catch (NumberFormatException e) {
            return false;
        }
        return true;

    }
}
