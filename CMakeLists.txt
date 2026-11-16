cmake_minimum_required(VERSION 3.23)
project(INP2026FinalProject
	VERSION 1.0.0
)
add_subdirectory(src)

install(
	TARGETS client server
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/lib
)
