main: src/main.o src/room.o src/Tools/savedata.o src/Tools/utils.o  src/UI/dialog.o src/UI/message.o
	g++ -lncurses -lpanel  -o Test src/main.o src/room.o src/Tools/utils.o src/Tools/savedata.o src/UI/dialog.o src/UI/message.o

room.o: src/room.cpp src/room.h
	g++ -c -lncurses src/room.cpp

savedata.o: src/Tools/savedata.cpp src/Tools/savedata.hpp src/Tools/utils.hpp
	g++ -c src/Tools/savedata.cpp

dialog.o: src/UI/dialog.cpp src/UI/dialog.hpp src/Tools/utils.hpp
	g++ -c -lncurses -lpanel src/UI/dialog.cpp

message.o: src/UI/message.cpp src/UI/message.hpp src/UI/dialog.hpp
	g++ -c -lncurses -lpanel src/UI/message.cpp

utils.o: src/Tools/utils.cpp src/Tools/utils.hpp src/UI/dialog.hpp
	g++ -c -lncurses -lpanel src/Tools/utils.cpp

clean: 
	rm src/*.o src/*/*.o