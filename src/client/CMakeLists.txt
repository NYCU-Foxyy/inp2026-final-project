include(CheckIncludeFile)

set(REQUIRED_HEADERS
	curses.h
)

set(SOURCE_FILES
	main.cpp
	display.cpp
	input.cpp
)

foreach(header IN LISTS REQUIRED_HEADERS)
	check_include_file(${header} HAVE_REQUIRED_HEADER)
endforeach()

add_executable(client ${SOURCE_FILES})
target_link_libraries(client Common)
target_include_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(client PRIVATE ${CMAKE_SOURCE_DIR}/src)
