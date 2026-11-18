set(SOURCE_FILES
	tick.cpp
	network.cpp
	utils.cpp
)

add_library(CommonLib ${SOURCE_FILES})
target_include_directories(CommonLib
	PRIVATE ${CMAKE_SOURCE_DIR}/src
	PUBLIC ${CMAKE_SOURCE_DIR}/include
)
