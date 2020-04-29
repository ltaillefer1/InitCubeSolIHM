CFLAGS=-W -Wall -ansi -pedantic

all: InitCubeServeur

InitCubeServeur : InitCubeServeur.o
		g++ -lpthread -o InitCubeServeur InitCubeServeur.o $(CFLAGS)
InitCubeServeur.o : InitCubeServeur.cpp InitCubeServeur.h Communication.cpp
		g++ -lpthread -o InitCubeServeur.cpp Communication.cpp -c InitCubeServeur.o Communication.o $(CFLAGS)
CubeEventServer.o: CubeEventServer.cpp Communication.cpp
		g++ -lpthread -o CubeEventServer.cpp Communication.cpp -c CubeEventServer.o Communication.o $(CFLAGS)
Communication.o : Communication.cpp 
		g++ -lpthread -o Communication.cpp -c Communication.o $(CFLAGS)
clean : 
		rm -rf *.o
mrproper: clean
		rm -rf InitCubeServeur

