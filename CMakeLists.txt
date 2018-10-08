cmake_minimum_required (VERSION 2.6)
project (redispp)

add_subdirectory(
        lib
)

add_executable(
        redispp_tester
        main.cpp
)

target_link_libraries(
        redispp_tester
        redispp
)
