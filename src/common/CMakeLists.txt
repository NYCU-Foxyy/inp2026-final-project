set(SOURCE_FILES
	game.cpp
	network.cpp
	utils.cpp
)

add_library(Common ${SOURCE_FILES})
target_include_directories(Common
	PRIVATE ${CMAKE_SOURCE_DIR}/src
	PUBLIC ${CMAKE_SOURCE_DIR}/include
)
