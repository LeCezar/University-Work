package Domain.Statement;

import Domain.ADT.*;
import Domain.ProgramState;
import Exception.MyException;

public class CompStmt implements iStmt {
    private iStmt stmt1,stmt2;
    public CompStmt(iStmt stm1 , iStmt stm2) {
        this.stmt1 = stm1;
        this.stmt2 = stm2;
    }
    @Override
    public String toString(){
        return "(" + stmt1.toString() + ";" + stmt2.toString() + ")";
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyStack stack = state.getStack();
        stack.push(stmt2);
        stack.push(stmt1);
        return null;
    }
    public iStmt getFirst(){
        return stmt1;
    }
    public iStmt getSecond(){
        return stmt2;
    }

}
