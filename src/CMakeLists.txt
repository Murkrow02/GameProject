cmake_minimum_required(VERSION 3.21)
project(GameProject2)

set(CMAKE_CXX_STANDARD 14)


add_executable(GameProject2 Entities/xCrossShooter.cpp Entities/crossShooter.cpp Entities/xShooter.cpp Tools/ShopItem.hpp Engine/gameobject.hpp Tools/GameObjectNode.hpp Tools/GameObjectNode.cpp Tools/GameObjectList.hpp Tools/GameObjectList.cpp Tools/utils.cpp Tools/utils.hpp Tools/savedata.cpp Tools/savedata.hpp libraries/json.hpp Entities/weapon.cpp Entities/bullet.cpp Entities/foe.cpp Entities/vendor.cpp Entities/entity.hpp Entities/entity.cpp Entities/fruit.cpp  Entities/player.cpp Entities/player.hpp Entities/artifact.cpp Entities/artifact.hpp Entities/food.cpp Entities/key.cpp Entities/ladder.cpp UI/itemselector.hpp UI/itemselector.cpp UI/dialog.cpp UI/dialog.hpp UI/inventory.cpp UI/inventory.hpp UI/shop.cpp UI/shop.hpp UI/message.cpp UI/message.hpp UI/stats.cpp UI/stats.hpp Engine/main.cpp Engine/map.cpp Engine/map.hpp Engine/minimap.cpp Engine/map.hpp Engine/minimap.hpp Engine/room.cpp Engine/room.hpp)  
target_link_libraries(GameProject2 ncurses)
target_link_libraries(GameProject2 panel)
target_link_libraries(GameProject2 pthread)
