CXX = g++
CXXFLAGS = -std=c++11
VPATH = gfx core

export CXXFLAGS

all: libhume.a

libhume.a: Application.o Blittable.o Graphics.o Image.o Log.o State.o StateManager.o Timer.o Window.o WindowSettings.o
	$(AR) rvs $@ *.o

Application.o: Application.h
Blittable.o: Blittable.h
Graphics.o: Graphics.h
Image.o: Image.h
Log.o: Log.h LogMode.h
State.o: State.h
StateManager.o: StateManager.h
Timer.o: Timer.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
