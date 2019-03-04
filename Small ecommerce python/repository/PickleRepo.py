import pickle
from repository.Repository import *
class PickleRepository(Repository):
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
        f = open(self.__file, "wb")
        pickle.dump(self._objects, f)
        f.close()
    def loadFromFile(self):
        f = open(self.__file, "rb")

        """
        You cannot unpickle an empty file
            - EOFError means the file is empty
            - Exception means no file, not accessible and so on...
            - finally makes sure we close the input file, regardless of error
        """
        try:
            self._objects = pickle.load(f)
        except EOFError:
            self._objects = {}
        except Exception as e:
            raise e
        finally:
            f.close()

