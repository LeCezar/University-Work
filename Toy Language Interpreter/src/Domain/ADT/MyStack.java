package Domain.ADT;

import Exception.MyException;
import java.util.ArrayList;

public class MyStack <T> implements iMyStack<T>{
    private ArrayList<T> stack;
    private int top;
    public MyStack() {
        this.stack = new ArrayList<T>();
        this.top = -1;
    }
    public MyStack(iMyStack<T> stk){
        this.stack = stk.getAll();
    }
    @Override
    public void push(T elem){
        stack.add(++top,elem);

    }
    @Override
    public T pop() throws MyException{
        if( stack.size() == 0)
            throw new MyException("Empty stack \n");
        return stack.remove(top--);
    }
    @Override
    public T peek() throws MyException{
        if( stack.size() == 0)
            throw new MyException("Empty stack \n");
        return stack.get(top);
    }
    public String toString() {
        String returnString = "";
        for(int i = stack.size() - 1; i >= 0; i--)
        {
            returnString = returnString + stack.get(i).toString() + "\n";
        }
        return returnString;
    }

    @Override
    public boolean isEmpty() {

        return this.stack.isEmpty();
    }

    @Override
    public ArrayList<T> getAll() {
        return stack;
    }
}
