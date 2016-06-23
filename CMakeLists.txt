cmake_minimum_required(VERSION 2.8.11)
project(HUME)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -g")

include_directories(./)

if(${CMAKE_SYSTEM_NAME} STREQUAL "FreeBSD")
  include_directories(SYSTEM /usr/local/include)
  link_directories(/usr/local/lib)
endif()

# === add_sources
# Add a list of source files to the final executable build.
# SOURCES - list of source files to add
macro(add_sources ${SOURCES})
  foreach(src_file ${SOURCES})
	if(HUME_SOURCES)
	  set(full_path "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}")
	  list(APPEND HUME_SOURCES ${full_path})
	  set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
	else()
	  set(HUME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/${src_file}")
	  set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
	endif()
  endforeach()
endmacro()

add_subdirectory(audio)
add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(gfx)

add_library(hume STATIC ${HUME_SOURCES})
