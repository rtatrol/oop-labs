package calculator.utilits;

import calculator.operations.Operation_IDs;
import java.util.HashMap;

public class OperationUtils {
    private static final HashMap<Operation_IDs,String> idNameMap;
    private static final HashMap<String,Operation_IDs> nameIdMap;

    static{
        idNameMap=new HashMap<Operation_IDs,String>();
        idNameMap.put(Operation_IDs.DEFINE, "Define");
        idNameMap.put(Operation_IDs.DIVISION, "/");
        idNameMap.put(Operation_IDs.MULTIPLY, "*");
        idNameMap.put(Operation_IDs.POP, "Pop");
        idNameMap.put(Operation_IDs.PRINT, "Print");
        idNameMap.put(Operation_IDs.PUSH, "Push");
        idNameMap.put(Operation_IDs.SQRT, "Sqrt");
        idNameMap.put(Operation_IDs.SUBTRACTION, "-");
        idNameMap.put(Operation_IDs.SUM, "+");

        nameIdMap=new HashMap<String,Operation_IDs>();
        nameIdMap.put("Define", Operation_IDs.DEFINE);
        nameIdMap.put("/", Operation_IDs.DIVISION);
        nameIdMap.put("*", Operation_IDs.MULTIPLY);
        nameIdMap.put("Pop", Operation_IDs.POP);
        nameIdMap.put("Print", Operation_IDs.PRINT);
        nameIdMap.put("Push", Operation_IDs.PUSH);
        nameIdMap.put("Sqrt", Operation_IDs.SQRT);
        nameIdMap.put("-", Operation_IDs.SUBTRACTION);
        nameIdMap.put("+", Operation_IDs.SUM);
    }

    public static Operation_IDs getIdByName(String name){
        return nameIdMap.get(name);
    }
    public static String getNameById(Operation_IDs id){
        return idNameMap.get(id);
    }
    public static boolean isOperationName(String name){
        return nameIdMap.containsKey(name);
    }
}
