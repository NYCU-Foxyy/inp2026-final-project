set(TEST_PROG_LIST
	game-tick.test.cpp
)

create_test_sourcelist(Tests CommonTestDriver.cpp ${TEST_PROG_LIST})

add_executable(CommonTestDriver ${TEST_PROG_LIST})

target_link_libraries(CommonTestDriver CommonLib)

foreach(test_prog TEST_PROG_LIST)
	get_filename_component(test_name ${test_prog} NAME_WE)
	add_test(NAME ${test_name} COMMAND CommonTestDriver ${test_name})
endforeach()
