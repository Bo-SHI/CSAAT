cmake_minimum_required(VERSION 2.6)

project(MordorEX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CXX_FLAGS
 -g
 -std=c++11
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Werror
 -Wall
 -Wextra
 -Wconversion
 -Wno-unused-parameter
 -Woverloaded-virtual
 -Wpointer-arith
 # -Wshadow (violated by Mordor lib)
 -Wwrite-strings
 -Wunreachable-code
 -Wnon-virtual-dtor
 -Wno-unknown-pragmas #suppress rapidjson warnings
 -rdynamic #for backtraces obtaining
 -fno-strict-aliasing
)

string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# Check required libs
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED regex system thread)
find_package(ZLIB REQUIRED)

# Specify static link lib path
set(STATIC_LIB_PATH ${CMAKE_SOURCE_DIR}/libs/)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/third_party)

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

add_subdirectory(src)
