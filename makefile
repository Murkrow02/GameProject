main: src/main.o src/room.o src/utils.o
	g++ -lncurses -o Test src/main.o src/room.o src/utils.o

main.o: src/main.cpp src/headers/room.h src/headers/utils.h
	g++ -lncurses -c src/main.cpp

room.o: src/room.cpp src/headers/room.h
	g++ -lncurses -c src/room.cpp

utils.o: src/utils.cpp src/headers/utils.h
	g++ -lncurses -c src/utils.cpp


