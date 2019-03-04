package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Exception.MyException;

public class readHeap extends Exp {

    private String var_name;

    public readHeap(String name){
        this.var_name = name;
    }

    @Override
    public int eval(iMyDictionary<String, Integer> tbl, iMyHeap<Integer,Integer> heap) {
        try {
            return heap.getContent(tbl.getValue(this.var_name));
        }
        catch (MyException e){
            System.out.print(e.getMessage());
        }
        return 0;
    }

    @Override
    public String toString() {
        return this.var_name;
    }
}
