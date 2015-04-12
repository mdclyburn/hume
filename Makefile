CXX = g++
CXXFLAGS = -std=c++11

all: libhume.a

libhume.a: gfx/*.o
	$(AR) rvs $@ $^

gfx/*.o: gfx/*.cpp
	cd gfx && $(MAKE)

.PHONY: clean
clean:
	find . -name "*.o" -delete
	rm -f libhume.a
