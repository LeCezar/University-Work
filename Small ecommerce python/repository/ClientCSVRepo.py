from Domain.Domain import *
from repository.Repository import *
class ClientCSVRepository(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__file=fileName
    def add(self,object):
        Repository.add(self,object)
        self.__storeToFile()
    def remove(self,index):
        Repository.remove(self,index)
        self.__storeToFile()
    def update(self,oldObject,newObject):
        Repository.update(self,oldObject,newObject)
        self.__storeToFile()
    def __storeToFile(self):
        f = open(self.__file,'w')
        clients = Repository.getAll(self)
        for client in clients:
            strf=str(client.getClientID())+","+str(client.getName())+"\n"
            f.write(strf)
        f.close()
    def loadFromFile(self):
        f = open(self.__file,'r')
        line=f.readline().strip()
        try:
            while line != "" :
                attr=line.split(",")
                clientID=attr[0]
                Name=attr[1]
                client = Client(clientID,Name)
                Repository.add(self,client)
                line=f.readline().strip()
        except IOError:
            raise ValueError("Could not open file")
        finally:
            f.close()





