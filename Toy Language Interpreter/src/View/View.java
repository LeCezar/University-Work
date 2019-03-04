package View;

import Controller.*;
import Domain.ADT.*;
import Domain.Expression.*;
import Domain.ProgramState;
import Domain.Statement.*;
import Domain.Statement.writeHeap;
import Repository.*;
import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.File;


public class View {
    static File logfile = new File("/Users/LeCezar/Desktop/An 2 Sem 1/MAP/A2+/src/log_ProgramState");
    static iRepository repo = new Repository(logfile);
    static Controller controller = new Controller(repo);

    public static void main(String[] args) {


        iStmt v10 = new AssignStmt("v",new ConstExp(10));
        iStmt v32 = new AssignStmt("v",new ConstExp(32));
        iStmt newA = new newStmt("a" , new ConstExp(22));
        iStmt writeA = new writeHeap("a",new ConstExp(30));
        iStmt printV = new PrintStmt(new VarExp("v"));
        iStmt printA = new PrintStmt(new readHeap("a"));
        iStmt frk = new ForkStmt(new CompStmt(writeA , new CompStmt(v32 , new CompStmt(printV,printA))));
        iStmt prg = new CompStmt(v10 , new CompStmt(newA , new CompStmt(frk , new CompStmt(printV, printA))));


        iMyStack<iStmt> stack = new MyStack<>();
        stack.push(prg);
        iMyDictionary<String,Integer> symTable = new MyDictionary<>();
        iMyDictionary<Integer, Pair<String, BufferedReader>> fileTable = new MyDictionary<>();
        iMyList<Integer> out = new MyList<>();
        iMyHeap<Integer,Integer> heap = new MyHeap<>();
        ProgramState myProgram = new ProgramState(1,stack,symTable,out,fileTable,heap);
        controller.addProgram(myProgram);
        controller.allStep();

    }
}
