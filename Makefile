all: odate
	
odate: main.o Date.o
	g++ main.o Date.o -o odate
	
main.o: main.cpp
	g++ -c main.cpp
	
Date.o: Date.cpp
	g++ -c Date.cpp
	
clean:
	rm -rf *o odate
