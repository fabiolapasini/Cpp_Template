find_package(GTest REQUIRED)

add_executable(GetTotalBytes "get_total_bytes.test.cpp")

target_link_libraries(GetTotalBytes PRIVATE
	template_proj
	GTest::gmock_main
	GTest::gtest_main
)

add_test(NAME GetTotalBytes COMMAND GetTotalBytes)
gtest_discover_tests(GetTotalBytes)
