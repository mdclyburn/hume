CXX = g++
CXXFLAGS = -std=c++11 -I ./
LDFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
VPATH = audio gfx core unit-tests

export CXXFLAGS

all: libhume.a test cppcheck.xml

cppcheck.xml: libhume.a
	cppcheck --xml --xml-version=2 --enable={warning,style,performance,portability,information,missingInclude} --inconclusive --language=c++ -i unit-tests . &> cppcheck.xml

libhume.a: Audio.o Blittable.o Component.o Font.o Graphics.o Image.o Log.o Music.o Sound.o Text.o Timer.o Window.o WindowSettings.o
	$(AR) rvs $@ *.o

test: Timer_test.o libhume.a
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $^ -o $@

Audio.o: Audio.h
Blittable.o: Blittable.h
Component.o: Component.h
Font.o: Font.h
Graphics.o: Graphics.h
Image.o: Image.h
Log.o: Log.h
Music.o: Music.h
Sound.o: Sound.h
Text.o: Font.h
Timer.o: Timer.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

Timer_test.o: Timer.h

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
