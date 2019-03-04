package Domain.Statement;

import Domain.ADT.*;
import Domain.Expression.*;
import Domain.ProgramState;

public class ifStmt implements iStmt{
    private Exp exp;
    private iStmt thenS;
    private iStmt elseS;
    public ifStmt(Exp e,iStmt f,iStmt s){
        this.exp = e;
        this.thenS = f;
        this.elseS = s;
    }
    public String toString(){
        return "IF (" + exp.toString() + " THEN (" + thenS.toString() + ") ELSE (" + elseS.toString() + "))";
    }
    public ProgramState execute(ProgramState state){
        iMyStack stack = state.getStack();
        iMyHeap<Integer,Integer> heap = state.getHeap();
        iMyDictionary<String,Integer> SymTable = state.getSymTable();
        if(exp.eval(SymTable,heap)!=0)
            stack.push(thenS);
        else
            stack.push(elseS);
        return null;
    }
    public iStmt getThen(){
        return thenS;
    }
    public iStmt getElse(){
        return thenS;
    }
    public Exp getExp() {
        return exp;
    }
}
