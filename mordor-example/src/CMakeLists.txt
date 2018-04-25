FILE(GLOB_RECURSE SRCS *.cpp)

add_executable(gamesvr ${SRCS})
target_link_libraries(gamesvr
    ${STATIC_LIB_PATH}/libmordor.a
    rt dl # runtime support
    pthread ssl crypto z #libs referenced by libmordor
    ${Boost_LIBRARIES})
