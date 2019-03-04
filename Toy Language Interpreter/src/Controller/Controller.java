package Controller;


import Domain.ProgramState;
import Repository.iRepository;
import java.util.*;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;

public class Controller {
    private iRepository repo;
    private ExecutorService executor;

    public Controller(iRepository repo){
        this.repo = repo;
    }
    private Map<Integer, Integer> conservativeGarbageCollector(Collection<Integer> symTableValues, Map<Integer,Integer> heap){
        return heap.entrySet().stream().filter(e->symTableValues.contains(e.getKey())).collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
    }

    public void closeAllFiles(ProgramState prg){
        prg.getFileTable().getAll().entrySet().forEach(e->{
        try
            {e.getValue().getValue().close();}
        catch (Exception el)
            {System.out.print(el.getMessage());}});
    }

    private List<ProgramState> removeCompletedPrg(List<ProgramState> inLst){
        return inLst.stream().filter(p -> p.isNotCompleted()).collect(Collectors.toList());
    }

    private void oneStepAll(List<ProgramState> lstPrg) throws Exception{
        lstPrg.forEach(prg -> repo.logProgramState(prg));
        List<Callable<ProgramState>> callList = lstPrg.stream().map((ProgramState p) -> (Callable<ProgramState>)(() -> {return p.oneStep();})).collect(Collectors.toList());
        List<ProgramState> newLstPrg = executor.invokeAll(callList).stream().map(future -> {
                try{return future.get();}
                catch (Exception e){
                    System.out.print(e.getMessage());
                    return null;
                    }
            }).filter(p -> p!=null).collect(Collectors.toList());
        lstPrg.addAll(newLstPrg);
        lstPrg.forEach(prg -> repo.logProgramState(prg));
        repo.setPrgList(lstPrg);
    }
    public void allStep() {

        executor = Executors.newFixedThreadPool(2);
        List<ProgramState> lstPrg = removeCompletedPrg(repo.getPrgList());
        while (lstPrg.size() > 0) {
            lstPrg.get(0).setHeap(this.conservativeGarbageCollector(lstPrg.get(0).getSymTable().getAll().values(), lstPrg.get(0).getHeap().getAll()));
            try {
                oneStepAll(lstPrg);
            } catch (Exception e) {
                System.out.print(e.getMessage());
            }
            lstPrg = removeCompletedPrg(repo.getPrgList());
        }
        executor.shutdownNow();
        repo.close_log();
    }


    public void addProgram(ProgramState state){
        repo.addProgram(state);
    }
    public String showProgram(){
        ProgramState prg = repo.getCurrentProgram();
        return prg.toString();
    }



}
