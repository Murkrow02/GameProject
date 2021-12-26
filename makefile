main: src/main.o src/room.o src/savedata.o src/utils.o
	g++ -lncurses -o Test src/main.o src/room.o src/utils.o src/savedata.o

room.o: src/room.cpp src/headers/room.h
	g++ -c -lncurses src/room.cpp

savedata.o: src/savedata.cpp src/headers/savedata.hpp src/utils.hpp
	g++ -c src/savedata.cpp

utils.o: src/utils.cpp src/utils.hpp
	g++ -c -lncurses src/utils.cpp

clean: 
	rm src/*.o