package Domain.ADT;

import java.util.HashMap;
import java.util.Map;

import Exception.MyException;

public class MyHeap<A,C> implements iMyHeap<A,C> {

    private Map<A,C> heap;

    public MyHeap(){
        this.heap = new HashMap<>();
    }
    public MyHeap(iMyHeap<A, C> heap) {this.heap = heap.getAll();}

    @Override
    public void assign(A address, C content) throws MyException {
            this.heap.put(address,content);
    }

    @Override
    public C getContent(A address) throws MyException {

        return heap.get(address);
    }

    @Override
    public boolean check_address(A address) {
        return heap.containsKey(address);
    }

    @Override
    public Map<A, C> getAll() {
        return this.heap;
    }

    @Override
    public void setAll(Map<A, C> mp) {
        this.heap = mp;
    }
    @Override

    public String toString(){
        String return_string = "";
        for(HashMap.Entry<A,C> map : this.heap.entrySet()){
            return_string = return_string + "Address: " + map.getKey().toString() + " Content: " + map.getValue().toString() + "\n";
        }
        return return_string;
    }
}
