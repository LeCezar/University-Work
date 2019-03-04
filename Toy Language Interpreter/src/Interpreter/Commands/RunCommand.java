package Interpreter.Commands;

import Controller.Controller;

public class RunCommand extends Command{
    private Controller ctr;
    int index;
    public RunCommand(String key,String desc,Controller ctr,int index){
        super(key,desc);
        this.ctr = ctr;
        this.index = index;
    }
//    public void execute(){
//        ctr.allStep(index);
//    }
}
