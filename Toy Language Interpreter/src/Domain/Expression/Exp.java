package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;


public abstract class Exp {
    abstract public int eval(iMyDictionary<String,Integer> tbl, iMyHeap<Integer,Integer> heap);
    abstract public String toString();
}
