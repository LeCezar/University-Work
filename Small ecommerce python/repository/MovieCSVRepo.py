from repository.Repository import *
from Domain.Domain import *


class MovieCSVRepository(Repository):
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
        movies = Repository.getAll(self)
        for movie in movies:
            strf = str(movie.getMovieID()) + "," + str(movie.getTitle())+ "," + str(movie.getDescription()) + ","+ str(movie.getGenre()) + "\n"
            f.write(strf)
        f.close()

    def loadFromFile(self):
        f = open(self.__file, 'r')
        line = f.readline().strip()
        try:
            while line != "":
                attr = line.split(",")
                movieID = attr[0]
                Title = attr[1]
                Descr = attr[2]
                Genre = attr[3]
                movie= Movie(movieID,Title,Descr,Genre)
                Repository.add(self, movie)
                line = f.readline().strip()
        except IOError:
            raise ValueError("Could not open file")
        finally:
            f.close()





