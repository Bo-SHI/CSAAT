FILE(GLOB_RECURSE SRCS *.cpp)

add_executable(a.out ${SRCS})
target_link_libraries(a.out
    rt dl # runtime support
    pthread ssl crypto z #libs referenced by libmordor
    ${Boost_LIBRARIES})
