package Domain.ADT;
import Exception.MyException;

import java.util.Map;

public interface iMyHeap<A,C>{
    void assign(A address,C content) throws MyException;
    C getContent(A address) throws MyException;
    boolean check_address(A address);
    void setAll(Map<A,C> mp);
    Map<A,C> getAll();
    String toString();
}
