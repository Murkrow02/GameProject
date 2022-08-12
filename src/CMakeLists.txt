cmake_minimum_required(VERSION 3.21)
project(GameProject2)

set(CMAKE_CXX_STANDARD 14)


add_executable(GameProject2 Tools/ShopItem.hpp Tools/GameObjectList.hpp Tools/GameObjectList.cpp Tools/utils.cpp Tools/utils.hpp Tools/savedata.cpp Tools/savedata.hpp libraries/json.hpp Entities/weapon.cpp Entities/bullet.cpp Entities/foe.cpp Entities/dummy.cpp Entities/entity.hpp Entities/entity.cpp Entities/player.cpp Entities/player.hpp Entities/food.cpp UI/itemselector.hpp UI/itemselector.cpp  UI/alert.cpp UI/alert.hpp UI/dialog.cpp UI/dialog.hpp UI/shop.cpp UI/shop.hpp UI/message.cpp UI/message.hpp UI/stats.cpp UI/stats.hpp Engine/main.cpp Engine/map.cpp Engine/map.h Engine/minimap.cpp Engine/map.h Engine/minimap.h Engine/room.cpp Engine/room.h)  
target_link_libraries(GameProject2 ncurses)
target_link_libraries(GameProject2 panel)
target_link_libraries(GameProject2 pthread)