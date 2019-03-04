package Domain.Statement;

import Domain.ADT.iMyStack;
import Domain.Expression.Exp;
import Domain.ProgramState;
import Exception.MyException;

public class whileStmt implements iStmt{

    private Exp ex;

    private iStmt stmt;

    public whileStmt(Exp ex,iStmt stmt){
        this.ex = ex;
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {

        iMyStack stack = state.getStack();

        if(ex.eval(state.getSymTable(),state.getHeap()) == 0){
            return null;
        }
        else
        {
            stack.push(this);
            stack.push(stmt);
            return null;
        }

    }

    @Override
    public String toString() {
        return "while(" + ex.toString() + ")";
    }
}
