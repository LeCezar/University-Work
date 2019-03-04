package Interpreter;

import Controller.Controller;
import Domain.ADT.*;
import Domain.Expression.ConstExp;
import Domain.Expression.VarExp;
import Domain.ProgramState;
import Domain.Statement.*;
import Repository.*;

import Interpreter.Commands.*;
import javafx.util.Pair;

import java.io.BufferedReader;
import java.io.File;

public class Interpreter {
    public static void main(String[] args) {
//            iStmt ifStmt = new ifStmt(new VarExp("var_c"),new CompStmt(new readFile(new VarExp("File"),"var_c"),new PrintStmt(new VarExp("var_c"))),new PrintStmt(new ConstExp(0)));
//            iStmt opStmt = new openRFile("File","/Users/LeCezar/IdeaProjects/A2+/src/Domain/Statement/test.in");
//            iStmt readStmt = new readFile(new VarExp("File"),"var_c");
//            iStmt closeStmt = new closeRFile(new VarExp("File"));
//            iStmt ex2 = new CompStmt(opStmt,new CompStmt(readStmt,new CompStmt(new PrintStmt(new VarExp("var_c")),closeStmt)));
//            iStmt ex1=new CompStmt(new AssignStmt("a", new ConstExp(10)), new PrintStmt(new VarExp("a")));
//            iMyStack<iStmt> stack = new MyStack<>();
//            iMyHeap<Integer,Integer> heap1 = new MyHeap<>();
//            stack.push(ex1);
//            iMyDictionary<String,Integer> symTable = new MyDictionary<>();
//            iMyList<Integer> out = new MyList();
//            iMyDictionary<Integer, Pair<String, BufferedReader>> fileTable = new MyDictionary<>();
//            iMyStack<iStmt> stack2 = new MyStack<>();
//            iMyHeap<Integer,Integer> heap2 = new MyHeap<>();
//            stack2.push(ex2);
//            iMyDictionary<String,Integer> symTable2 = new MyDictionary<>();
//            iMyList<Integer> out2 = new MyList();
//            iMyDictionary<Integer, Pair<String, BufferedReader>> fileTable2 = new MyDictionary<>();
//            ProgramState prg1 = new ProgramState(stack,symTable,out, ex1,fileTable,heap1);
//            ProgramState prg2 = new ProgramState(stack2,symTable2,out2, ex2,fileTable2,heap2);
//            File logfile = new File("/Users/LeCezar/IdeaProjects/A2+/src/log_ProgramState");
//
//            iRepository repo1 = new Repository(logfile);
//
//            repo1.addProgram(prg1);
//            repo1.addProgram(prg2);
//
//            Controller ctr1 = new Controller(repo1);
//
//            TextMenu menu = new TextMenu();
//            menu.addCommand(new ExitCommand("0", "exit"));
//            menu.addCommand(new RunCommand("1",ex1.toString(),ctr1,0));
//            menu.addCommand(new RunCommand("2",ex2.toString(),ctr1,1));
//            menu.show();
//        }
    }
}

