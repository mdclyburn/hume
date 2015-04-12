CXX = g++
CXXFLAGS = -std=c++11
VPATH = gfx

export CXXFLAGS

all: libhume.a

libhume.a: Blittable.o Image.o Window.o WindowSettings.o
	$(AR) rvs $@ *.o

Blittable.o: Blittable.h
Image.o: Image.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
