package Domain.ADT;
import Exception.MyException;

import java.util.Map;
import java.util.Set;

public interface iMyDictionary<K,V> {
    void put(K key,V value);
    boolean checkKey(K key);
    Set<K> keySet();
    void update(K key,V value);
    V getValue(K key) throws MyException;
    boolean isDefined(K key);
    String toString();
    void setAll(Map<K,V> mp);
    Map<K,V> getAll();
}
