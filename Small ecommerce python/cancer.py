from datetime import *
from Domain.Domain import *
rental= Rental ("2","5","2",date(2017,11,10),date(2017,12,3),date.min)
strf = str(rental.getRentalID()) + "," + str(rental.getMovieID())+ "," + str(rental.getClientID()) + ","+ str(rental.getRentalDate())+","+str(rental.getDueDate())+","+str(rental.getReturnedDate()) + "\n"
attr= strf.split(",")
print(attr[5].strip())