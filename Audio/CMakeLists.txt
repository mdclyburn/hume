include_directories(${HUME_SOURCE_DIR})

set(SOURCES
  Audio.cpp
  Music.cpp
  SDLMixerException.cpp
  Sound.cpp)

add_sources("${SOURCES}")

set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
