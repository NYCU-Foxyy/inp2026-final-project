include(CheckIncludeFile)

set(REQUIRED_HEADERS
	curses.h
)

set(SOURCE_FILES
	main.cpp
	display.cpp
)

foreach(header IN LISTS REQUIRED_HEADERS)
	check_include_file(${header} HAVE_REQUIRED_HEADER)
endforeach()

list(REMOVE_ITEM SOURCE_FILES "main.cpp")

add_library(ClientLib ${SOURCE_FILES})
add_executable(ClientExe main.cpp)

target_include_directories(ClientLib
	PRIVATE
		${CMAKE_SOURCE_DIR}/include/client
		${CMAKE_SOURCE_DIR}/include/common
)
target_link_libraries(ClientLib CommonLib)

target_include_directories(ClientExe
	PRIVATE
		${CMAKE_SOURCE_DIR}/include/client
		${CMAKE_SOURCE_DIR}/include/common
)
target_link_libraries(ClientExe CommonLib ClientLib)
