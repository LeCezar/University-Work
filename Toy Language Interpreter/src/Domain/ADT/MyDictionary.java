package Domain.ADT;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import Exception.MyException;

public class MyDictionary<K,V> implements iMyDictionary<K,V> {
    private Map<K, V> dictionary;

    public MyDictionary() {
        this.dictionary = new HashMap<K, V>();
    }
    public MyDictionary(iMyDictionary<K, V> dict) {
        this.dictionary = dict.getAll();
    }

    @Override
    public void put(K key, V value) {
        this.dictionary.put(key, value);
    }

    @Override
    public void update(K key, V value) {
        this.dictionary.replace(key, value);
    }

    @Override
    public V getValue(K key) throws MyException {
        V value = this.dictionary.get(key);
        if(value == null)
            throw new MyException("Key not mapped");
        return this.dictionary.get(key);
    }
    @Override
    public boolean checkKey(K key){
        if(this.dictionary.get(key) == null)
            return false;
        else
            return true;
    }
    @Override
    public Set<K> keySet(){
        return this.dictionary.keySet();
    }

    @Override
    public boolean isDefined(K key) {

        return this.dictionary.containsKey(key);
    }

    @Override
    public String toString() {
        String return_string = "";
        for(HashMap.Entry<K,V> map : this.dictionary.entrySet()){
            return_string = return_string + "Key: " + map.getKey().toString() + " Value: " + map.getValue().toString() + "\n";
        }
        return return_string;
    }

    @Override
    public Map<K, V> getAll() {
        return this.dictionary;
    }

    @Override
    public void setAll(Map<K, V> mp) {
        this.dictionary = mp;
    }
}
