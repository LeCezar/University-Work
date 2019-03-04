package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;


public class ArithExp extends Exp {
    private Exp e1;
    private Exp e2;
    private int op;
    private String oop;

    /**
     op = 0 -> +
     op = 1 -> -
     op = 2 -> *
     op = 3 -> /
     */

    public ArithExp(String opp,Exp e1, Exp e2){
        this.e1 = e1;
        this.e2 = e2;
        this.oop = opp;
        int nr = -1;
        if( opp.equals("+"))
            nr = 0;
        if( opp.equals("-"))
            nr = 1;
        if( opp.equals("*"))
            nr = 2;
        if(opp.equals("/"))
            nr = 3;
        this.op = nr;
    }

    @Override
    public int eval(iMyDictionary<String,Integer> symTable, iMyHeap<Integer,Integer> heap){
        if( op == 0){
            return e1.eval(symTable,heap) + e2.eval(symTable,heap);
        }
        if( op == 1){
            return e1.eval(symTable,heap) - e2.eval(symTable,heap);
        }
        if( op == 2){
            return e1.eval(symTable,heap) * e2.eval(symTable,heap);
        }
        if( op == 3 && e2.eval(symTable,heap) != 0){
            return e1.eval(symTable,heap) / e2.eval(symTable,heap);
        }
        return 0;
    }

    @Override
    public String toString() {
        return e1.toString() + " " + this.oop + " " + e2.toString();
    }

    public Exp getFirst() {
        return e1;
    }

    public Exp getSecond() {
        return e2;
    }

    public int getOperand() {
        return op;
    }
}
