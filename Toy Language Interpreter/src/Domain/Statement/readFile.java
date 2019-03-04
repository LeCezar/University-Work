package Domain.Statement;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Domain.Expression.Exp;
import Domain.ProgramState;
import javafx.util.Pair;
import Exception.MyException;

import java.io.BufferedReader;

public class readFile implements iStmt{

    private Exp file_descriptor;
    private String var_name;

    public readFile(Exp desc,String var){
        this.var_name = var;
        this.file_descriptor = desc;
    }
    @Override
    public ProgramState execute(ProgramState state) throws MyException{

        iMyDictionary<String,Integer> symTable = state.getSymTable();
        iMyDictionary<Integer, Pair<String,BufferedReader>> fileTable = state.getFileTable();
        iMyHeap<Integer,Integer> heap = state.getHeap();
        try {
            symTable.put(this.var_name, Integer.parseInt(fileTable.getValue(file_descriptor.eval(symTable,heap)).getValue().readLine()));
        }
        catch (Exception e){
            throw new MyException(e.getMessage());
        }
        return null;
    }
    @Override
    public String toString(){
        return var_name + " = " + "read(" + file_descriptor.toString() +")";
    }

}
