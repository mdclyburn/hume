CXX = g++
CXXFLAGS = -std=c++11 -I ./
LDLIBS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
VPATH = audio gfx app core unit-tests

export CXXFLAGS

all: libhume.a test cppcheck.xml

cppcheck.xml:
	cppcheck --xml --xml-version=2 --enable={warning,style,performance,portability,information,missingInclude} --inconclusive --language=c++ -i unit-tests . &> cppcheck.xml

libhume.a: Application.o Audio.o Blittable.o Component.o Font.o Graphics.o Image.o Log.o Music.o Properties.o Sound.o State.o Text.o Timer.o Window.o WindowSettings.o
	$(AR) rcvs $@ *.o

test: Timer_test.o libhume.a
	$(CXX) $(CXXFLAGS) $(LDLIBS) $^ -o $@

Application.o: Application.h
Audio.o: Audio.h
Blittable.o: Blittable.h
Component.o: Component.h
Font.o: Font.h
Graphics.o: Graphics.h
Image.o: Image.h
Log.o: Log.h
Music.o: Music.h
Properties.o: Properties.h
Sound.o: Sound.h
State.o: State.h
Text.o: Font.h
Timer.o: Timer.h
Window.o: Window.h
WindowSettings.o: WindowSettings.h

Timer_test.o: Timer.h

documentation.pdf: doc/latex/refman.tex
	cd doc/latex && pdflatex refman.tex && pdflatex refman.tex
	mv doc/latex/refman.pdf documentation.pdf

doc/latex/refman.tex: Doxyfile app/* audio/* core/* gfx/*
	doxygen Doxyfile

.PHONY: clean unittest
clean:
	find . -name "*.o" -delete
	$(RM) libhume.a cppcheck.xml test documentation.pdf
	$(RM) -r doc

unittest: test
	./test
