include_directories(${PROJECT_SOURCE_DIR/include/})

set(SOURCE_FILES
	game.cpp
	network.cpp
	utils.cpp
)

add_library(Common ${SOURCE_FILES})
