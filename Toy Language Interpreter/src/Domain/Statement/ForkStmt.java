package Domain.Statement;

import Domain.ProgramState;
import Exception.MyException;
import Domain.ADT.*;

public class ForkStmt implements iStmt{

    private iStmt stmt;

    public ForkStmt(iStmt stmt){
        this.stmt = stmt;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {

        iMyStack<iStmt> newStack = new MyStack<>();
        newStack.push(this.stmt);
        iMyDictionary<String,Integer> newSym = new MyDictionary<>(state.getSymTable());
        iMyHeap newHeap = state.getHeap();
        iMyDictionary newFileTable = state.getFileTable();
        iMyList newOut = state.getOut();
        return new ProgramState(state.getId() * 10,newStack,newSym,newOut,newFileTable,newHeap);
    }

    @Override
    public String toString() {
        return "fork (" + stmt.toString() + ")";
    }
}
