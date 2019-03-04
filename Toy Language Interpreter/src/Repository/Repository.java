package Repository;
import Domain.ProgramState;

import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements iRepository {
    List<ProgramState> programRepo;
    int currentProgram;
    PrintWriter print;

    public Repository(File logFile){
        this.programRepo = new ArrayList<>();
        this.currentProgram = -1;
        try {
            this.print = new PrintWriter(logFile);
        }
        catch(Exception e){
            System.out.print(e.getMessage());
        }
    }
    public void addProgram(ProgramState state){
        programRepo.add(0,state);
    }
    public void logProgramState(ProgramState state) {

        try {
            print.append(state.toString());

        }catch (Exception e){
            System.out.print(e.getMessage());
        }
    }
    public void close_log(){
        this.print.close();
    }
    public ProgramState getCurrentProgram() {
        return programRepo.get(currentProgram);
    }
    public ProgramState getProgram(int index){
        return programRepo.get(index);
    }

    @Override
    public List<ProgramState> getPrgList() {
        return this.programRepo;
    }

    @Override
    public void setPrgList(List<ProgramState> lst) {
        this.programRepo = lst;
    }

}
