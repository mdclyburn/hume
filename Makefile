CXX = g++
CXXFLAGS = -std=c++11
VPATH = audio gfx core

export CXXFLAGS

all: libhume.a

libhume.a: Audio.o Blittable.o Font.o Graphics.o Image.o Log.o State.o StateManager.o Sound.o Text.o Timer.o Window.o WindowSettings.o
	$(AR) rvs $@ *.o

Audio.o: Audio.h
Blittable.o: Blittable.h
Font.o: Font.h
Graphics.o: Graphics.h
Image.o: Image.h
Log.o: Log.h LogMode.h
Sound.o: Sound.h
Text.o: Font.h
Timer.o: Timer.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
