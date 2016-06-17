include_directories(${HUME_SOURCE_DIR})

set(SOURCES
  Application.cpp
  State.cpp)

add_sources("${SOURCES}")

set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
