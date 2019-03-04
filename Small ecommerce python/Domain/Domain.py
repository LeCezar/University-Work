class Movie:
    '''
    Instance for this class will represent a Movie
    '''
    def __init__(self,movieID,title,description,genre):
        """
        Construct for Movie
        IN: movieId, the title of the movie, the description and the genre
        """
        self.__movieID=movieID
        self.__title=title
        self.__description=description
        self.__genre=genre
    def setMovieID(self,movieID):
        '''
        setter for ID
        in: movieID
        '''
        self.__movieID=movieID

    def setTitle(self,title):
        self.__title=title
    def setDescription(self,description):
        self.__description=description
    def setGenre(self,genre):
        self.__genre=genre
    def getMovieID(self):
        '''
        Getter for movie ID
        '''
        return self.__movieID
    def getTitle(self):
        return self.__title
    def getDescription(self):
        return self.__description
    def getGenre(self):
        return self.__genre
    def __str__(self):
        s="Movie ID: "+self.__movieID+"\n"
        s+="Title: "+self.__title+"\n"
        s+="Genre: "+self.__genre+"\n"
        s+="Description: "+self.__description+"\n"
        return s
class Client:
    '''
    Instance of this class will repesent a Client
    '''
    def __init__(self,clientID,name):
        """
        Constructor for Client
        In: client ID,name

        """
        self.__clientID=clientID
        self.__name=name
    def setClientID(self,clientID):
        '''
        Setter for client id
        '''
        self.__clientID=clientID
    def setName(self,name):
        self.__name=name
    def getClientID(self):
        '''
        Getter for client id
        :return:
        '''
        return self.__clientID
    def getName(self):
        return self.__name
    def __str__(self):
        s="ClientID: "+self.__clientID+"\n"
        s+="Name: "+self.__name+"\n"
        return s
class Rental:
    def __init__(self,rentalID,movieID,clientID,rentalDate,dueDate,returnedDate):
        '''

      Constructor for Rentals
        '''
        self.__rentalID=rentalID
        self.__movieID=movieID
        self.__clientID=clientID
        self.__rentalDate=rentalDate
        self.__dueDate=dueDate
        self.__returnedDate=returnedDate

    def setRentalID(self,rentalID):
        self.__rentalID=rentalID
    def setMovieID(self,movieID):
        self.__movieID=movieID
    def setClientID(self,clientID):
        self.__clientID=clientID
    def setRentalDate(self,rentalDate):
        self.__rentalDate=rentalDate
    def setDueDate(self,dueDate):
        self.__dueDate=dueDate
    def setReturnedDate(self,returnedDate):
        self.__returnedDate=returnedDate
    def getRentalID(self):
        return self.__rentalID
    def getMovieID(self):
        return self.__movieID
    def getClientID(self):
        return self.__clientID
    def getRentalDate(self):
        return self.__rentalDate
    def getDueDate(self):
        return self.__dueDate
    def getReturnedDate(self):
        return self.__returnedDate
    def __str__(self):
        s="Rental ID: "+self.__rentalID+"\n"
        s+="Movie ID: "+self.__movieID+"\n"
        s+="Client ID: "+self.__clientID+"\n"
        s +="Rental Date: " + self.__rentalDate + "\n"
        s +="Due date: " + self.__rentalDate + "\n"
        s +="Returned date"+ self.__returnedDate+ "\n"
        return s

    '''
    Setters and getters
    '''

def testClient():
    client1=Client("1",'Gigel')

    client1.setClientID('2')
    assert client1.getClientID()=='2'

    client1.setName('Cezar')
    assert client1.getName()=='Cezar'
def testMovie():
    movie=Movie('567','Deadpool','Your mama is fat','Action Comedy Drama')

    movie.setMovieID('ABC')
    assert movie.getMovieID()=='ABC'

    movie.setDescription('Nope')
    assert movie.getDescription()=='Nope'
def testRental():
    rental=Rental('ABCD','1234','PORC','15.07.2017','25.07.2017','24.07.2017')

    rental.setRentalID('AJK')
    assert rental.getRentalID()=='AJK'

testClient()
testMovie()
testRental()

