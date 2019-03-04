package Domain.Statement;

import Domain.ProgramState;
import Exception.MyException;

public interface iStmt {
    String toString();
    ProgramState execute(ProgramState state) throws MyException;
}
