package Domain.ADT;

import java.util.Queue;

public interface iMyList<T> {
    Queue<T> getAll();
    void queue(T e);
    T dequeue();
    T peekFirst();
    String toString();
}
