package Domain;
import Domain.ADT.*;
import Domain.Statement.iStmt;
import javafx.util.Pair;
import Exception.MyException;

import java.io.BufferedReader;
import java.util.Map;


public class ProgramState {
    int id;
    iMyStack<iStmt> stack;
    iMyDictionary<String,Integer> SymTable;
    iMyDictionary<Integer,Pair<String, BufferedReader>> fileTable;
    iMyList<Integer> outer;
    iMyHeap<Integer,Integer> Heap;

    public ProgramState(int id,iMyStack<iStmt> stk, iMyDictionary<String,Integer> symtbl, iMyList<Integer> ot,iMyDictionary<Integer, Pair<String, BufferedReader>> fileTable,iMyHeap<Integer,Integer> heap){
        this.id = id;
        this.stack = stk;
        this.SymTable = symtbl;
        this.outer = ot;
        this.fileTable = fileTable;
        this.Heap = heap;
    }
    public boolean isNotCompleted(){
        return !(stack.isEmpty());
    }

    public ProgramState oneStep() throws MyException{
        if(stack.isEmpty())
            throw new MyException("ID: " + this.id + " says: \"Nothing to execute (stack empty)\"");
        iStmt crtStmt = stack.pop();
        return crtStmt.execute(this);
    }

    public iMyDictionary<Integer, Pair<String, BufferedReader>> getFileTable() {
        return fileTable;
    }

    public void setFileTable(iMyDictionary<Integer, Pair<String, BufferedReader>> fileTable) {
        this.fileTable = fileTable;
    }

    public void setId(int id) { this.id = id; }

    public int getId() { return id; }

    public iMyHeap<Integer,Integer> getHeap() {
        return Heap;
    }

    public void setHeap(Map<Integer,Integer> heap) {
        this.Heap.setAll(heap);
    }

    public iMyStack<iStmt> getStack() {
        return this.stack;
    }

    public void setExeStack(iMyStack<iStmt> stack) {
        this.stack = stack;
    }

    public iMyDictionary<String, Integer> getSymTable() {
        return this.SymTable;
    }

    public void setSymTable(iMyDictionary<String, Integer> SymTable) {
        this.SymTable = SymTable;
    }

    public iMyList<Integer> getOut() {
        return this.outer;
    }

    public void setOut(iMyList<Integer> out) {
        this.outer = out;
    }



    public iStmt getNextStmt() throws MyException {
        return this.stack.peek();
    }

    public String toString() {
        return "<><><><><><><><><><><><><><><><><><><><>\n" + "ID: " + this.id + "\n" +"ExeStack:\n" + stack.toString() + "\n" + "Sym Table:\n" + SymTable.toString() + "\n" + "Heap:\n" + Heap.toString() + "\n" + "File table:\n" + fileTable.toString() + "\n" +"Print output:\n" + outer.toString();
    }
}

