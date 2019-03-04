package Domain.Statement;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Domain.Expression.Exp;
import Domain.ProgramState;
import javafx.util.Pair;
import Exception.MyException;

import java.io.BufferedReader;

public class closeRFile implements iStmt{
    private Exp exp_descriptor;

    public closeRFile(Exp ex){
        this.exp_descriptor = ex;
    }
    @Override
    public ProgramState execute(ProgramState state)throws MyException {
        iMyDictionary<Integer, Pair<String,BufferedReader>> fileTable = state.getFileTable();
        iMyDictionary<String,Integer> symTable = state.getSymTable();
        iMyHeap<Integer,Integer> heap = state.getHeap();
        BufferedReader buff = fileTable.getValue(this.exp_descriptor.eval(symTable,heap)).getValue();
        try{
            buff.close();}
            catch (Exception e){
            throw new MyException(e.getMessage());
            }
        return null;
    }
    public String toString(){
        return "Close (" + exp_descriptor.toString() + ")";
    }
}
