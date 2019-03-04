package Domain.Expression;

import Domain.ADT.*;
import Exception.MyException;
public class VarExp extends Exp{
    private String id;

    public VarExp(String id){
        this.id = id;
    }
    @Override
    public int eval(iMyDictionary<String,Integer> symTable, iMyHeap<Integer,Integer> heap) {
        try {


            return symTable.getValue(id);
        }
        catch (MyException e){
            System.out.print(e.getMessage());
        }
        return 0;
    }
    @Override
    public String toString(){
        return id;
    }

    public String getId() {
        return id;
    }
}
