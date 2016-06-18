include_directories(${HUME_SOURCE_DIR})

set(SOURCES
  Component.cpp
  Log.cpp
  Timer.cpp)

add_sources("${SOURCES}")

add_subdirectory(exceptions)

set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
