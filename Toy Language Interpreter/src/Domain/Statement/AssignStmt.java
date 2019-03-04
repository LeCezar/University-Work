package Domain.Statement;

import Domain.ADT.*;
import Domain.Expression.Exp;
import Domain.ProgramState;
import Exception.MyException;

public class AssignStmt implements iStmt {
    private String id;
    private Exp exp;

    public AssignStmt(String id,Exp e){
        this.id = id;
        this.exp = e;
    }
    public String toString(){
        return id + " = " + exp.toString();
    }
    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyDictionary<String,Integer> symTable = state.getSymTable();
        iMyHeap<Integer,Integer> heap = state.getHeap();
        int val = exp.eval(symTable,heap);
        if (symTable.isDefined(id))
              symTable.update(id,val);
        else
            symTable.put(id,val);
        return null;
    }

    public Exp getExp() {
        return exp;
    }

    public String getId() {
        return id;
    }
}
