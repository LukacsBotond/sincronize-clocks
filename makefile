CFLAGS = -Wall -lpthread -std=c++17 -g

timeServer: ./src/timeserver/*.cpp ./src/timeserver/*.hpp ./src/common/*.cpp ./src/common/*.h
	g++ -o ./exec/timeserver ./src/timeserver/*.cpp ./src/common/*.cpp $(CFLAGS)

kliens: ./src/kliens/*.cpp ./src/kliens/*.hpp ./src/common/*.cpp ./src/common/*.h
	g++ -o ./exec/kliens ./src/kliens/*.cpp ./src/common/*.cpp $(CFLAGS)

all: kliens timeServer

clean: 
	rm -f kliens
	rm -f timeServer