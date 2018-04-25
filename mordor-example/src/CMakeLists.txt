FILE(GLOB_RECURSE SRCS *.cpp)

add_executable(mordorex ${SRCS})
target_link_libraries(mordorex
    ${STATIC_LIB_PATH}/libmordor.a
    rt dl # runtime support
    pthread ssl crypto z #libs referenced by libmordor
    ${Boost_LIBRARIES})
