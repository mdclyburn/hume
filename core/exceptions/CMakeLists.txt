include_directories(${HUME_SOURCE_DIR})

set(SOURCES
  BadFileException.cpp
  Exception.cpp
  SDLException.cpp)

add_sources("${SOURCES}")

set($HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
