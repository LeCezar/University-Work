package Domain.ADT;

import java.util.LinkedList;
import java.util.Queue;


public class MyList<T> implements  iMyList<T>{

    private Queue<T> list;

    public MyList(){
        this.list = new LinkedList<T>() {
        };

    }
    public MyList(iMyList<T> lst){
        this.list = lst.getAll();
    }
    @Override
    public void queue(T e) {
        list.add(e);
    }

    @Override
    public T dequeue() {
        return list.remove();
    }

    @Override
    public T peekFirst() {
        return list.peek();
    }
    @Override
    public String toString() {
        String returnString = "";
        for(T e : list)
        {
            returnString = returnString + e.toString() + "\n";
        }
        return returnString;
    }

    @Override
    public Queue<T> getAll(){
        return this.list;
    }

}


