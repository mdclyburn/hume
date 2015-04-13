CXX = g++
CXXFLAGS = -std=c++11
VPATH = gfx core

export CXXFLAGS

all: libhume.a

libhume.a: Blittable.o Graphics.o Image.o Log.o Window.o WindowSettings.o
	$(AR) rvs $@ *.o

Blittable.o: Blittable.h
Graphics.o: Graphics.h
Image.o: Image.h
Log.o: Log.h LogMode.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
