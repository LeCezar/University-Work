package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;

public class ConstExp extends Exp {
    private int number;
    public ConstExp(int number){
        this.number = number;
    }

    public int eval(iMyDictionary<String,Integer> tbl, iMyHeap<Integer,Integer> heap){
        return number;
    }
    public String toString(){
        return Integer.toString(number);
    }

    public int getNumber() {
        return number;
    }
}
