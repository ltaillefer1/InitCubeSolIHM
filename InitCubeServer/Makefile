CFLAGS=-W -Wall -ansi -pedantic

all: InitCubeServeur

InitCubeServeur : InitCubeServeur.o
		g++ -lpthread -o InitCubeServeur InitCubeServeur.o $(CFLAGS)
InitCubeServeur.o : InitCubeServeur.cpp Communication.cpp
		g++ -lpthread -o InitCubeServeur.cpp Communication.cpp $(CFLAGS)
CubeEventServer.o: CubeEventServer.cpp Communication.cpp
		g++ -lpthread -o CubeEventServer.cpp Communication.cpp $(CFLAGS)
Communication.o : Communication.cpp 
		g++ -lpthread -o Communication.cpp $(CFLAGS)
clean : 
		rm -rf *.o
mrproper: clean
		rm -rf InitCubeServeur

