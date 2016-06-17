include_directories(${HUME_SOURCE_DIR})

set(SOURCES
Blittable.cpp
Font.cpp
Graphics.cpp
Image.cpp
Properties.cpp
Text.cpp
Window.cpp
WindowSettings.cpp)

add_sources("${SOURCES}")

set(HUME_SOURCES ${HUME_SOURCES} PARENT_SCOPE)
