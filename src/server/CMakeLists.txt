set(SOURCE_FILES
	main.cpp
)

add_executable(ServerExe ${SOURCE_FILES})
target_link_libraries(ServerExe CommonLib)
target_include_directories(ServerExe PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_directories(ServerExe PRIVATE ${CMAKE_SOURCE_DIR}/src)
