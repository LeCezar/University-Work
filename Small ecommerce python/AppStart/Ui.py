from datetime import date
from datetime import timedelta
from Domain.Domain import *

class UI:
    def __init__(self,ClientController,MovieController,RentController,undoController):
        self.__CC=ClientController
        self.__MC=MovieController
        self.__RC=RentController
        self.__UC=undoController
    def start(self):
        while True:
            UI.Menu()
            try:
                cmd=int(input("Imput option >> "))
            except:
                print("Invalid input")
            if cmd==1:
                option=int(input("Press 1 for Client manager, 2 for Movie manager >> "))
                UI.manager(self,option)
            elif cmd==2:
                UI.renter(self)
            elif cmd==3:
                opt=int(input("Search client (1) or movie (2) >> "))
                UI.search(self,opt)
            elif cmd==4:
                UI.statistics(self)
            elif cmd==5:
                self.__UC.undo()
            elif cmd==6:
                self.__UC.redo()
            elif cmd==0:
                print ("See ya!")
                break
            else:
                print("Invalid command")

    @staticmethod
    def Menu():
        s="Select option:"+"\n"
        s+="1. Manage lists"+"\n"
        s+="2. Rent a movie"+"\n"
        s+="3. Search"+"\n"
        s+="4. Show statistics"+"\n"
        s+="5. Undo"+"\n"
        s+="6. Redo" + "\n"
        s+="0. Exit"+ "\n"
        print (s)

    def menuManager(self,opt):
        if opt==1:
            str="client "
        elif opt==2:
            str="movie "
        else:
            print("Invalid command ")
            return
        s="1.Add "+str+"\n"
        s+="2.Remove "+str+"\n"
        s+="3.Update "+str+"\n"
        s+="4.List "+str+"\n"
        s += "0.Back " + "\n"
        print (s)
    def manager(self,opt):
        while True:
            UI.menuManager(self,opt)
            cmd=int(input("Chose one of the options"))
            if cmd==1:
                if opt==1:
                    ClientID=input("Client ID=")
                    poz=self.__CC.findByID(ClientID)
                    if poz != -1:
                        print("Client already in list")
                    else:
                        Name=input("Name=")
                        self.__CC.add(ClientID,Name)

                elif opt==2:
                    MovieID=input("MovieID= ")
                    poz=self.__MC.findByID(MovieID)
                    if poz!=-1:
                        print("Movie already added")
                    else:
                        self.__MC.add(MovieID ,input("Title="),input("Description="),input("Genre"))

            if cmd==2:
                if opt==1:
                    ClientID=input("Introduce clientID for the removal")
                    poz=self.__CC.findByID(ClientID)
                    if poz == -1:
                        print("Client not found")
                    else:
                        self.__CC.remove(poz)
                        print("Removal complete")
                if opt==2:
                    MovieID=input("Introduce movieID for the removal")
                    poz=self.__MC.findByID(MovieID)
                    if poz == -1:
                        print("Movie not found")
                    else:
                        self.__MC.remove(poz)
                        print("Removal complete")
            if cmd==3:
                if opt==1:
                    id=input("Id of the old client")
                    poz=self.__CC.findByID(id)
                    if poz == -1:
                        print("Client not found")
                    else:
                        name=input("New Name=")
                        '''
                        Put remove and add in update
                        '''
                        NewClient=Client(id,name)
                        self.__CC.update(self.__CC.get(poz),NewClient)
                if opt==2:
                    id=input("Id of the movie")
                    poz=self.__MC.findByID(id)
                    if poz == -1:
                        print("Movie not found")
                    else:
                        name=input("New Name=")
                        description=input("New description=")
                        genre=input("New genre=")
                        NewMovie=Movie(id,name,description,genre)
                        self.__MC.update(self.__MC.get(poz),NewMovie)

            if cmd==4:
                if opt==1:
                    print(self.__CC.list())
                if opt==2:
                    print(self.__MC.list())
            if cmd==0:
                break
    def renter(self):
        try:
            rentalID=input("RentalID =")
            poz=self.__RC.findByID(rentalID)
            if poz!=-1:
                print("Rental already added")
            else:
                clientID=input("clientID")
                poz=self.__CC.findByID(clientID)
                if poz == -1:
                    print("Client does not exist")

                movieID=input("movie ID")
                poz = self.__MC.findByID(movieID)
                if poz == -1:
                    print("Movie does not exist")
                rentalDate=date.today()
                time2Weeks=timedelta(days=14)
                dueDate=rentalDate+time2Weeks
                returnedDate=date.min
                self.__RC.add(rentalID,movieID,clientID,rentalID,dueDate,returnedDate)
        except:
            print("Client may have unreturned movies that passed the due date or the movie is already rented")

    def MenuSearch(self,opt):
        if opt==1:
            s="1. Search client by id "+"\n"
            s+="2. Search clinet by name "+"\n"
            s += "0. Back " + "\n"
            print(s)
        elif opt==2:
            s="1. Search movie by id "+"\n"
            s+="2. Search movie by title "+"\n"
            s += "3. Search movie by description " + "\n"
            s += "4. Search movie by genre " + "\n"
            s += "0. Back " + "\n"
            print(s)
        else:
            print("Invalid command ")
            return


    def search(self,opt):
        while True:
            UI.MenuSearch(self,opt)
            cmd=int(input("Introduce selection >> "))
            if cmd==1:
                if opt==1:
                    ID=input("ID for searh = ")
                    print(self.__CC.filterID(ID))
                if opt==2:
                    ID=input("ID for searh = ")
                    print(self.__MC.filterID(ID))
            elif cmd==2:
                if opt==1:
                    name=input("Name for search = ")
                    print(self.__CC.filterName(name))
                if opt==2:
                    title=input("Title for search = ")
                    print(self.__MC.filterTitle(title))
            elif cmd==3:
                if opt==1:
                    print("Invalid command")
                if opt==2:
                    description=input("Description for search")
                    print(self.__MC.filterDescription(description))
            elif cmd==4:
                if opt==1:
                    print("Invalid command")
                if opt==2:
                    genre=input("Genre for search")
                    print(self.__MC.filterGenre(genre))
            elif cmd==0:
                break
            else:
                print("Invalid Command")
    def StatsMenu(self):
        s="1.Stats by times a movie was rented "+"\n"
        s+="2.Stats by days a movie was rented "+"\n"
        s+="3.Stats for clients "+"\n"
        s+="4.Late rentals"+"\n"
        s+="0. Back"+"\n"
        print (s)
    def statistics(self):
        while True:
            UI.StatsMenu(self)
            cmd=int(input("Wich one? >> "))
            if cmd==1:
                print(self.__RC.movieStatistics(1))
            elif cmd==2:
                print(self.__RC.movieStatistics(2))
            elif cmd==3:
                print(self.__RC.clientStatistic())
            elif cmd==4:
                print(self.__RC.lateRentals())
            elif cmd==0:
                break
            else:
                print("Invalid command")

