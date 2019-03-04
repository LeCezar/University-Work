package Repository;

import Domain.ProgramState;

import java.util.List;

public interface iRepository {
    ProgramState getCurrentProgram();
    ProgramState getProgram(int index);
    void addProgram(ProgramState state);
    public void logProgramState(ProgramState state);
    public void close_log();
    List<ProgramState> getPrgList();
    void setPrgList(List<ProgramState> lst);


}
