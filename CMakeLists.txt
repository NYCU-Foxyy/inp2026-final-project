cmake_minimum_required(VERSION 3.23)
project(INP2026FinalProject
	VERSION 1.0.0
)

option(BUILD_TESTING "Enable testing and build tests" ON)

add_subdirectory(src)

set_target_properties(
	ClientExe
	PROPERTIES
	OUTPUT_NAME "client"
)

set_target_properties(
	ServerExe
	PROPERTIES
	OUTPUT_NAME "server"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

install(TARGETS ClientExe ServerExe)

if (BUILD_TESTING)
	enable_testing()
	add_subdirectory(tests)
endif()
