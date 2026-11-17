set(SOURCE_FILES
	main.cpp
)

add_executable(server ${SOURCE_FILES})
target_link_libraries(server Common)
target_include_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(server PRIVATE ${CMAKE_SOURCE_DIR}/src)
