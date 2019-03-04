package Interpreter.Commands;

public abstract class Command {
    private String key,desciprtion;
    public Command(String key,String desciprtion){
        this.key = key;
        this.desciprtion = desciprtion;
    }
//    public abstract void execute();
    public String getKey(){
        return key;
    }
    public String getDesciprtion(){
        return this.desciprtion;
    }

}
