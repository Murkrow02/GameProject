cmake_minimum_required(VERSION 3.21)
project(GameProject2)

set(CMAKE_CXX_STANDARD 14)


add_executable(GameProject2 Tools/list.hpp Tools/list.cpp Tools/utils.cpp Tools/utils.hpp Tools/savedata.cpp Tools/savedata.hpp libraries/json.hpp Entities/bullet.cpp Entities/foe.cpp Entities/dummy.cpp Entities/entity.hpp Entities/entity.cpp Entities/player.cpp Entities/player.hpp UI/alert.cpp UI/alert.hpp UI/dialog.cpp UI/dialog.hpp UI/menu.cpp UI/menu.hpp UI/message.cpp UI/message.hpp UI/puzzle.cpp UI/puzzle.hpp UI/stats.cpp UI/stats.hpp Engine/main.cpp Engine/map.cpp Engine/map.h Engine/minimap.cpp Engine/map.h Engine/minimap.h Engine/room.cpp Engine/room.h)  
target_link_libraries(GameProject2 ncurses)
target_link_libraries(GameProject2 panel)
target_link_libraries(GameProject2 pthread)