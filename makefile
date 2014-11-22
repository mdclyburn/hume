CC = g++
ARGS = -std=c++11
OUT = libhume.a

$(OUT): Animation.o Application.o Audio.o Blittable.o Font.o FontManager.o Sound.o State.o Image.o Logger.o Music.o StateManager.o Text.o Timer.o Window.o WindowSettings.o
	ar rvs $(OUT) $^

Animation.o: Animation.cpp
	$(CC) -c Animation.cpp $(ARGS)
Application.o: Application.cpp
	$(CC) -c Application.cpp $(ARGS)
Audio.o: Audio.cpp
	$(CC) -c Audio.cpp $(ARGS)
Blittable.o: Blittable.cpp
	$(CC) -c Blittable.cpp $(ARGS)
Font.o: Font.cpp
	$(CC) -c Font.cpp $(ARGS)
FontManager.o: FontManager.cpp
	$(CC) -c FontManager.cpp $(ARGS)
State.o: State.cpp
	$(CC) -c State.cpp $(ARGS)
Image.o: Image.cpp
	$(CC) -c Image.cpp $(ARGS)
Logger.o: Logger.cpp
	$(CC) -c Logger.cpp $(ARGS)
Music.o:
	$(CC) -c Music.cpp $(ARGS)
Sound.o:
	$(CC) -c Sound.cpp $(ARGS)
StateManager.o: StateManager.cpp
	$(CC) -c StateManager.cpp $(ARGS)
Text.o: Text.cpp
	$(CC) -c Text.cpp $(ARGS)
Timer.o: Timer.cpp
	$(CC) -c Timer.cpp $(ARGS)
Window.o: Window.cpp
	$(CC) -c Window.cpp $(ARGS)
WindowSettings.o:
	$(CC) -c WindowSettings.cpp $(ARGS)

clean:
	rm -rf *.o $(OUT)
