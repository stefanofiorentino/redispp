include_directories(
        ${CMAKE_SOURCE_DIR}
        /usr/include/hiredis
)

add_library(
        redispp
        redispp.cpp
)

target_link_libraries(
        redispp
        hiredis
)