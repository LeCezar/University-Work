package Domain.Expression;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyHeap;

public class boolExp extends Exp {

    private Exp ex1,ex2;
    private int operator;

    /*
    -> 0 - <
    -> 1 - <=
    -> 2 - ==
    -> 3 - !=
    -> 4 - >
    -> 5 - >=
     */
    public boolExp(Exp ex1, Exp ex2,int operator){
        this.ex1 = ex1;
        this.ex2 = ex2;
        this.operator = operator;
    }

    @Override
    public int eval(iMyDictionary<String, Integer> tbl, iMyHeap<Integer, Integer> heap) {

        if(operator == 0){
            if(ex1.eval(tbl,heap) < ex2.eval(tbl, heap))
                return ex1.eval(tbl,heap);
            else
                return ex2.eval(tbl,heap);
        }
        if(operator == 1){
            if(ex1.eval(tbl,heap) <= ex2.eval(tbl, heap))
                return ex1.eval(tbl,heap);
            else
                return ex2.eval(tbl,heap);
        }
        if(operator == 3){
            if(ex1.eval(tbl,heap) == ex2.eval(tbl, heap))
                return ex1.eval(tbl,heap);
            else
                return 0;
        }
        if(operator == 4){
            if(ex1.eval(tbl,heap) > ex2.eval(tbl, heap))
                return ex1.eval(tbl,heap);
            else
                return ex2.eval(tbl,heap);
        }
        if(operator == 5){
            if(ex1.eval(tbl,heap) >= ex2.eval(tbl, heap))
                return ex1.eval(tbl,heap);
            else
                return ex2.eval(tbl,heap);
        }

        return 0;
    }

    @Override
    public String toString() {

        return ex1.toString() + Integer.toString(this.operator) + ex2.toString();
    }
}
