from Domain.Domain import Client
class Repository:
    def __init__(self):
        self.__data=[]
    def add(self,object):
        self.__data.append(object)
    def __str__(self):
        s=" "
        for x in self.__data:
            s+=" "+str(x)
    def __len__(self):
        return len(self.__data)
    def remove(self,index):
        '''Remove an element
        In: INDEX
        Out: removed element
        Exception: Index out of range
        '''
        if index<0 or index>len(self.__data):
            raise RepositoryException("Index out of range")
        self.__data.pop(index)
    def find(self,object):
        '''
        Find the index of an object
        In: object
        Out: Index
        '''
        for i in range (len(self.__data)):
            if self.__data[i]==object:
                return i
        return -1
    def getAll(self):
        return self.__data
    def get(self,index):
        if index<0 or index>len(self.__data):
            raise RepositoryException("Invalid element position")
        return self.__data[index]
    def removeAll(self):
        self.__data.clear()
    def update(self,oldObject,newObject):
        """
        Replace the first appearance of oldObject with newObject
        oldNumber - The number to be replaced
        newNumber - The updated number
        """
        lst=[]
        for i in range(0, len(self.__data)):
            if self.__data[i] != oldObject:
                lst.append(self.__data[i])
            else:
                lst.append(newObject)
                i+=1
        self.__data=lst


class RepositoryException(Exception):
    """
    Exception class for repository errors
    """
    def __init__(self, message):
        """
        Constructor for repository exception class
        message - A string representing the exception message
        """
        self.__message = message

    def __str__(self):
        return self.__message
def testRepository():
    testList=[Client('13B','Gigel Boaru'),Client('97A','Marcel Ghita'),Client('1B6CT','Cezar Misunel')]
    repoTest=Repository()

    for i in range(0,len(testList)):
        repoTest.add(testList[i])
        assert repoTest.get(i)==testList[i]

    assert repoTest.find(testList[1])==1

    repoTest.update(testList[1],testList[0])
    assert repoTest.get(1)==testList[0]

    repoTest.remove(0)
    assert repoTest.get(0)==testList[0]


testRepository()









