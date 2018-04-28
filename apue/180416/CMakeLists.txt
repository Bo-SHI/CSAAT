set(SRCS echo_whole_environ.c)

add_executable(echo ${SRCS})
target_link_libraries(echo
    apue)
