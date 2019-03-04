package Domain.Statement;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Domain.Expression.Exp;
import Domain.ProgramState;
import Exception.MyException;

public class writeHeap implements iStmt {

    private String var_name;
    private Exp ex;

    public writeHeap(String var_name,Exp ex){
        this.var_name = var_name;
        this.ex = ex;
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyHeap<Integer,Integer> heap = state.getHeap();
        iMyDictionary<String,Integer> symTable = state.getSymTable();

        if(!heap.check_address(symTable.getValue(var_name)))
            throw new MyException("Address dosen't exist");

        heap.assign(symTable.getValue(var_name),ex.eval(symTable,heap));


        return null;
    }

    @Override
    public String toString() {
        return "writeHeap(" + var_name + "," + ex.toString() +")";
    }
}
