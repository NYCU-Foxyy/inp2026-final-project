include_directories(${INP2026FinalProject_SOURCE_DIR}/include)
link_directories(${INP2026FinalProject_SOURCE_DIR}/src)

set(SOURCE_FILES
	main.cpp
	display.cpp
)

add_executable(client ${SOURCE_FILES})
target_link_libraries(client Common)
