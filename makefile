CC = g++
ARGS = -std=c++11
OUT = libhume.a

$(OUT): Blittable.o Font.o Game.o GameState.o Image.o Logger.o Sound.o Sprite.o StateManager.o Text.o Tile.o TileMap.o Timer.o Window.o WindowSettings.o
	ar rvs $(OUT) *.o

Blittable.o: Blittable.cpp
	$(CC) -c Blittable.cpp $(ARGS)
Font.o: Font.cpp
	$(CC) -c Font.cpp $(ARGS)
Game.o: Game.cpp
	$(CC) -c Game.cpp $(ARGS)
GameState.o: GameState.cpp
	$(CC) -c GameState.cpp $(ARGS)
Image.o: Image.cpp
	$(CC) -c Image.cpp $(ARGS)
Logger.o: Logger.cpp
	$(CC) -c Logger.cpp $(ARGS)
Sound.o: Sound.cpp
	$(CC) -c Sound.cpp $(ARGS)
Sprite.o: Sprite.cpp
	$(CC) -c Sprite.cpp $(ARGS)
StateManager.o: StateManager.cpp
	$(CC) -c StateManager.cpp $(ARGS)
Text.o: Text.cpp
	$(CC) -c Text.cpp $(ARGS)
Tile.o: Tile.cpp
	$(CC) -c Tile.cpp $(ARGS)
TileMap.o: TileMap.cpp
	$(CC) -c TileMap.cpp $(ARGS)
Timer.o: Timer.cpp
	$(CC) -c Timer.cpp $(ARGS)
Window.o: Window.cpp
	$(CC) -c Window.cpp $(ARGS)
WindowSettings.o:
	$(CC) -c WindowSettings.cpp $(ARGS)

clean:
	rm -rf *.o $(OUT)
