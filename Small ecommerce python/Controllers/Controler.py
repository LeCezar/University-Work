from Domain.Domain import *
from repository.Repository import *
from datetime import date
from Controllers.undoController import *

class ClientController:
    def __init__(self,repo,undoController):
        '''
        initialization of the client controller
        :param repo:
        '''
        self.__repo=repo
        self.__undoController=undoController
    def add(self,clientID,name):
        '''
        In: client ID, name
        create the object client and add it to the repo
        '''
        client=Client(clientID,name)
        self.__repo.add(client)
        redo=FunctionCall(self.add,clientID,name)
        poz=self.findByID(clientID)
        undo=FunctionCall(self.remove,poz)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)
    def remove(self,poz):
        '''
        Remove client at poz
        IN: poz
        '''

        redo=FunctionCall(self.remove,poz)
        undo=FunctionCall(self.add,self.__repo.get(poz).getClientID(),self.__repo.get(poz).getName())
        self.__repo.remove(poz)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)

    def update(self,oldItem,newItem):
        '''
        Updates old client with new client
        '''
        redo=FunctionCall(self.update,oldItem,newItem)
        undo=FunctionCall(self.update,newItem,oldItem)
        self.__repo.update(oldItem,newItem)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)

    def cleanList(self):
        '''
        Deletes the whole repository of clients
        :return:
        '''
    def list(self):
        '''
        List all clients
        :return:
        '''
        s=""
        for i in range(len(self.__repo)):
            s+=str(self.__repo.get(i))+"\n"
        return s
    def filterID(self,ID):
        '''

        '''
        search=""
        for i in range(len(self.__repo)):
            if ID.lower() in self.__repo.get(i).getClientID().lower():
                search+=str(self.__repo.get(i))+"  "
        return search

    def filterName(self,name):
        '''
        Function for filtering Clients by name, returns all clients with contain the parameter given
        In: name of client or any string for that matter
        '''
        search=""
        for i in range(len(self.__repo)):
            if name.lower() in self.__repo.get(i).getName().lower():
                search+=str(self.__repo.get(i))+"  "
        return search
    def findByID(self,clientID):
        '''
        Filters the clients by searching the parameter client ID

        IN: Client ID

        '''
        for i in range(0,len(self.__repo)):
            if clientID == self.__repo.get(i).getClientID():
                return i
        return -1
    def get(self,poz):
        '''
        Gives the object at the position
        :param poz:
        :return:
        '''
        return self.__repo.get(poz)

class MovieController:
    def __init__(self,repo,undoController):
        '''
        Initialization of movie controller
        :param repo:
        '''
        self.__repo=repo
        self.__undoController=undoController
    def add(self,movieID,title,description,genre):
        '''
        Creates object movie and adds it to the repository
        IN: movieID, title, descriprion, genre
        :return:
        '''
        movie=Movie(movieID,title,description,genre)
        redo=FunctionCall(self.add,movieID,title,description,genre)
        self.__repo.add(movie)
        poz=self.findByID(movieID)
        undo=FunctionCall(self.remove(poz))
        self.__undoController.newOperation()
        operation=Operation(redo,undo)
        self.__undoController.recordOperation(operation)

    def findByID(self,movieID):
        '''
        Searches the repository for the movie id given
        IN: movieID
        :return:
        '''
        for i in range(len(self.__repo)):
            if movieID == self.__repo.get(i).getMovieID():
                return i
        return -1

    def remove(self,poz):
        '''
        Removes the movie at the given position
        IN: Movie
        '''
        redo=FunctionCall(self.remove,poz)
        undo=FunctionCall(self.add,self.__repo.get(poz).getMovieID(),self.__repo.get(poz).getTitle(),self.__repo.get(poz).getDescription(),self.__repo.get(poz).getGenre())
        self.__repo.remove(poz)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)
    def update(self,oldItem,newItem):
        '''
        Updates old movie with new movie
        '''
        redo=FunctionCall(self.update,oldItem,newItem)
        undo=FunctionCall(self.update,newItem,oldItem)
        self.__repo.update(oldItem,newItem)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)

    def cleanList(self):
        '''
        Deletes the whole repository
        '''
        self.__repo.removeAll()
    def list(self):
        '''
        List all movies
        '''
        s=""
        for i in range(len(self.__repo)):
            s+=str(self.__repo.get(i))+"\n"
        return s
    def filterID(self,ID):
        '''
        All filter function search by the given parameter in repository and lists all the results that match
        '''
        search=""
        for i in range(len(self.__repo)):
            if ID.lower() in self.__repo.get(i).getMovieID().lower():
                search+=str(self.__repo.get(i))+"  "
        return search
    def filterTitle(self,Title):
        search=""
        for i in range(len(self.__repo)):
            if Title.lower() in self.__repo.get(i).getTitle().lower():
                search+=str(self.__repo.get(i))+"  "
        return search
    def filterDescription(self,Description):
        search=""
        for i in range(len(self.__repo)):
            if  Description.lower() in self.__repo.get(i).getDescription().lower():
                search+=str(self.__repo.get(i))+"  "
        return search
    def filterGenre(self,Genre):
        search=""
        for i in range(len(self.__repo)):
            if Genre.lower() in self.__repo.get(i).getGenre().lower():
                search+=str(self.__repo.get(i))+"  "
        return search
    def get(self,poz):
        '''
        Gives the object at the position
        :param poz:
        :return:
        '''
        return self.__repo.get(poz)

class RentalController:
    def __init__(self,repo,undoController):
        '''
        Initialization of repository
        :param repo:
        '''
        self.__repo=repo
        self.__undoController=undoController
    def addDone(self,rental):
        '''
        Adds a rental to repository
        In: object rental
        :return:
        '''
        redo=FunctionCall(self.addDone,rental)
        poz=self.findByID(rental.getRentalID())
        undo=FunctionCall(self.remove,poz)
        self.__repo.add(rental)
        operation=Operation(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)
    def remove(self,poz):
        '''
        rRemoves rental
        '''
        if poz<0 or poz>len(self.__repo):
            raise ValueError("Index out of range")
        redo=FunctionCall(self.remove,poz)
        undo=FunctionCall(self.add,self.__repo.get(poz).getRentalID(),self.__repo.get(poz).getMovieID(),self.__repo.get(poz).getClientID(),self.__repo.get(poz).getRentalDate(),self.__repo.get(poz).getDueDate(),self.__repo.get(poz).getReturnedDate())
        self.__repo.remove(poz)
        operation=(redo,undo)
        self.__undoController.newOperation()
        self.__undoController.recordOperation(operation)
    def removeAll(self):
        '''
        Removes all rentals
        :return:
        '''
        self.__repo.removeAll()
    def removeRentalByClient(self,clientID):
        '''
        removes all rentals of that client
        :return:
        '''
        for i in range (0,len(self.__repo)):
            if clientID == self.__repo.get(i).getClientID:
                self.__repo.remove(i)
    def removeRentalByMovie(self,movieID):
        '''
        removes all rentals of that movie
        :return:
        '''
        for i in range (0,len(self.__repo)):
            if movieID == self.__repo.get(i).getMovieID:
                self.__repo.remove(i)

    def update(self,oldItem,newItem):
        '''
        Updates old rental with new one
        '''
        self.__repo.update(oldItem,newItem)
    def updateReturnedDate(self,rentalID,returnedDate):
        '''
        Updates the retunred date of a rental
        In: rental ID and the new returned date
        '''
        poz=RentalController.findByID(self,rentalID)
        if poz==-1:
            raise ValueError("Item not in rentals")
        rentalUp=self.__repo.get(poz)
        rentalUp.setReturnedDate(returnedDate)
        self.__repo.update(self.__repo.get(poz),rentalUp)
    def add(self,rentalID,movieID,clientID,rentalDate,dueDate,returnedDate):
        '''
        Gets all the parameter for a rental, checks if they math (if the client can rent a movie and if the movie is available)
        and then creates the Object rental
        IN: rentalID, movieID, clientID, rentalDate, dueDate, returnedDate
        OUT: rental
        :return:
        '''
        rental = Rental(rentalID, movieID, clientID, rentalDate, dueDate, returnedDate)
        for i in range(0,len(self.__repo)):
            if movieID == self.__repo.get(i).getMovieID():
                raise ValueError("Movie already rented")
            if clientID == self.__repo.get(i).getClientID():
                today=date.today
                timeDelta=today - self.__repo.get(i).getDueDate()
                if (int(timeDelta.days))<0:
                    raise ValueError("Client has passed")
        RentalController.addDone(self,rental)

    def findByID(self,rentalID):
        '''
        Searches Rental repository for the given rentalID
        IN: rentalID
        :return:
        '''
        for i in range(len(self.__repo)):
            if rentalID == self.__repo.get(i).getRentalID:
                return i
        return -1
    def validator(self,lst,id):
        '''
        Checks if the id is in the list and returns the position if found
        in:lst, id
        out: position
        :return:
        '''
        for i in range(len(lst)):
            if id in lst[i][0]:
                return i
        return -1
    def movieStatistics(self,cmd):
        '''
       Makes a list of Movied with the times they were rented and total days, sorts depeding on command(1 for times 2 for days)
       IN: cmd
        :return:
        '''
        movieStatsList=[]
        for i in range(len(self.__repo)):
            poz = RentalController.validator(self, movieStatsList, self.__repo.get(i).getMovieID())
            timedelta = self.__repo.get(i).getReturnedDate() - self.__repo.get(i).getRentalDate()
            if poz != -1:
                movieStatsList[poz][1]+=1
                movieStatsList[poz][2]+=timedelta.days
            else:
                statistic=[self.__repo.get(i).getMovieID(),1,int(timedelta.days)]
                movieStatsList.append(statistic)
        if cmd==1:
            listSortedByTimes=sorted(movieStatsList,key=lambda value:value[1],reverse=True)
            return listSortedByTimes
        elif cmd==2:
            listSortedByDays=sorted(movieStatsList, key=lambda value:value[2],reverse=True)
            return listSortedByDays
    def clientStatistic(self):
        '''
        Makes a list of all clients sorted by the total ammount fo days they have rented
        :return:
        '''
        clientStatsList=[]
        for i in range(len(self.__repo)):
            poz = RentalController.validator(self,clientStatsList, self.__repo.get(i).getClientID())
            timedelta = self.__repo.get(i).getReturnedDate() - self.__repo.get(i).getRentalDate()
            if poz != -1:
                clientStatsList[poz][1]+=int(timedelta.days)
            else:
                stat=[self.__repo.get(i).getClientID(),int(timedelta.days)]
                clientStatsList.append(stat)
        sort=sorted(clientStatsList,key=lambda value:value[1],reverse=True)
        return sort
    def listRentals(self):
        '''
        lists all rentals
        :return:
        '''
        s=" "
        for i in range(len(self.__repo)):
            s+=str(self.__repo.get(i))+"\n"
        return s
    def lateRentals(self):
        '''
        Makes a list of rentals sorted asending by the days past due date
        :return:
        '''
        lateRentals=[]
        for i in range(len(self.__repo)):
            timedelta = self.__repo.get(i).getDueDate() - self.__repo.get(i).getReturnedDate()
            if int(timedelta.days)<0:
                stats=[self.__repo.get(i).getMovieID(),int(timedelta.days)]
                lateRentals.append(stats)
        sort=sorted(lateRentals,key= lambda value:value[1], reverse=False)
        return sort