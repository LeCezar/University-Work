from Controllers.Controler import *
from AppStart.Ui import *
from repository.ClientCSVRepo import *
from repository.MovieCSVRepo import *
from repository.RentalCSVRepo import *
from repository.PickleRepo import *
from Controllers.undoController import *




Settings="Settings"
def readSettings(Settings):
    f=open(Settings,"r")
    line=f.readline().strip()
    attr=line.split("=")
    if attr[1]=="CSV":
        line=f.readline().strip()
        file=line.split("=")
        repoC=ClientCSVRepository(file[1])
        line=f.readline().strip()
        file=line.split("=")
        repoM=MovieCSVRepository(file[1])
        line=f.readline().strip()
        file=line.split("=")
        repoR=RentalCSVRepository(file[1])
    if attr[1]=="binary":
        line=f.readline().strip()
        file=line.split("=")
        repoC=PickleRepository(file[1])
        line=f.readline().strip()
        file=line.split("=")
        repoM=PickleRepository(file[1])
        line=f.readline().strip()
        file=line.split("=")
        repoR=PickleRepository(file[1])
    repoC.loadFromFile()
    repoM.loadFromFile()
    repoR.loadFromFile()
    x=UndoController()

    controlerR = RentalController(repoR, x)
    controlerM = MovieController(repoM, x)
    controlerC = ClientController(repoC, x)

    ui = UI(controlerC, controlerM, controlerR, x)

    ui.start()


readSettings(Settings)

