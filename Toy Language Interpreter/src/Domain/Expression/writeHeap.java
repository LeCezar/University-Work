package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;
import Exception.MyException;

public class writeHeap extends Exp {

    private String var_name;
    private Exp ex;

    public writeHeap(String var_name,Exp ex){
        this.ex = ex;
        this.var_name = var_name;
    }

    @Override
    public int eval(iMyDictionary<String, Integer> tbl, iMyHeap<Integer,Integer> heap) {
        try {
            heap.assign(tbl.getValue(var_name), ex.eval(tbl, heap));
            return 1;
        }
        catch (MyException e){
            return 0;
        }
    }

    @Override
    public String toString() {
        return "writeHeap(" + var_name + "," + ex.toString() + ")";
    }
}
