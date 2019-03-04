package Domain.Statement;

import Domain.ADT.*;
import Domain.Expression.Exp;
import Domain.ProgramState;
import Exception.MyException;

public class PrintStmt implements iStmt {
    private Exp exp;
    public PrintStmt(Exp exp){
        this.exp = exp;
    }
    @Override
    public String toString(){
        return "print (" + exp.toString() + ")";
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyList out = state.getOut();
        iMyHeap<Integer,Integer> heap = state.getHeap();
        iMyDictionary sysTable = state.getSymTable();
        out.queue(exp.eval(sysTable,heap));
        return null;
    }

    public Exp getExp() {
        return exp;
    }
}
