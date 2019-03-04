package Domain.ADT;
import Exception.MyException;

import java.util.ArrayList;

public interface iMyStack<T> {
    void push(T elem);
    T pop() throws MyException;
    T peek() throws MyException;
    String toString();
    boolean isEmpty();
    ArrayList<T> getAll();
}
