package Domain.Statement;

import Domain.ADT.iMyDictionary;
import Domain.ADT.iMyStack;
import Domain.ProgramState;
import Exception.*;
import javafx.util.Pair;



import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Random;

public class openRFile implements iStmt {
    private String var_file_id;
    private String filename;
    private int file_descriptor;

    public openRFile(String id,String name){
        var_file_id = id;
        filename = name;

    }
    @Override
    public ProgramState execute(ProgramState state) throws MyException {
        iMyDictionary<Integer, Pair<String,BufferedReader>> fileTable = state.getFileTable();
        iMyDictionary<String,Integer> symTable = state.getSymTable();

        Random r = new Random();
        file_descriptor = r.nextInt();
        while(fileTable.checkKey(file_descriptor)){
            file_descriptor = r.nextInt();
        }

        for(Integer desc : fileTable.keySet()){
            if(fileTable.getValue(desc).getKey().equals(this.filename)){
                throw new MyException("Filename already in use");
            }
        }
        try{
            BufferedReader buff = new BufferedReader(new FileReader(this.filename));
            fileTable.put(this.file_descriptor,new Pair(this.filename,buff));
            symTable.put(var_file_id,file_descriptor);

        }catch (Exception e){
            throw new MyException(e.getMessage());
        }
        return null;

    }
    @Override
    public String toString(){
        return this.var_file_id + " = "+"open("+this.filename + ")";
    }
}
