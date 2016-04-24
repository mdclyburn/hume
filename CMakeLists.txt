cmake_minimum_required(VERSION 2.8.11)
project(HUME)

set(CMAKE_CXX_FLAGS "-std=c++11 -g")

include_directories(./)

set(HUME_SRC "")

include(app/CMakeLists.txt)
include(audio/CMakeLists.txt)
include(core/CMakeLists.txt)
include(gfx/CMakeLists.txt)

add_library(hume STATIC ${HUME_SRC})
