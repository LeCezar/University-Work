package Domain.Statement;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Domain.Expression.Exp;
import Domain.ProgramState;
import Exception.MyException;
import java.util.Random;

public class newStmt implements iStmt{
    private String var_name;
    private Exp ex;

    public newStmt(String var_name,Exp ex){
        this.ex = ex;
        this.var_name = var_name;
    }

    private int generate_address(iMyHeap<Integer,Integer> heap){
        Random r = new Random();
        int address;
        while(true){
            address = r.nextInt();
            if(address != 0 && !heap.check_address(address))
                return address;
        }
    }

    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyHeap<Integer,Integer> heap = state.getHeap();
        iMyDictionary<String,Integer> symTable = state.getSymTable();

        int address = this.generate_address(heap);
        heap.assign(address,ex.eval(symTable,heap));

        if (symTable.isDefined(var_name))
            symTable.update(var_name,address);
        else
            symTable.put(var_name,address);


        return null;
    }

    @Override
    public String toString() {
        return "new(" + var_name + "," + ex.toString() + ")";
    }
}
