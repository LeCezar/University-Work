from repository.Repository import *
from Domain.Domain import Rental
from datetime import date


class RentalCSVRepository(Repository):
    def __init__(self, fileName):
        Repository.__init__(self)
        self.__file = fileName

    def add(self, object):
        Repository.add(self, object)
        self.__storeToFile()

    def remove(self, index):
        Repository.remove(self, index)
        self.__storeToFile()

    def update(self, oldObject, newObject):
        Repository.update(self, oldObject, newObject)
        self.__storeToFile()

    def __storeToFile(self):
        f = open(self.__file, 'w')
        rentals = Repository.getAll(self)
        for rental in rentals:
            strf = str(rental.getRentalID()) + "," + str(rental.getMovieID())+ "," + str(rental.getClientID()) + ","+ str(rental.getRentalDate())+","+str(rental.getDueDate())+","+str(rental.getReturnedDate()) + "\n"
            f.write(strf)
        f.close()

    def loadFromFile(self):
        f = open(self.__file, 'r')
        line = f.readline().strip()
        try:
            while line != "":
                attr = line.split(",")
                rentalID=str(attr[0])
                movieID = str(attr[1])
                clientID=str(attr[2])
                rentDateStr=attr[3].split("-")
                rentalDate= date(int(rentDateStr[0]),int(rentDateStr[1]),int(rentDateStr[2]))
                dueDateStr=attr[4].split("-")
                dueDate= date(int(dueDateStr[0]),int(dueDateStr[1]),int(dueDateStr[2]))
                renturnDateStr=attr[5].split("-")
                returnDate= date(int(renturnDateStr[0]),int(renturnDateStr[1]),int(renturnDateStr[2]))
                rental= Rental(rentalID,movieID,clientID,rentalDate,dueDate,returnDate)
                Repository.add(self, rental)
                line = f.readline().strip()
        except IOError:
            raise ValueError("Could not open file")
        finally:
            f.close()





