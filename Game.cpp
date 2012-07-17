#include "Game.h"

namespace hm
{
	Game::Game() : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0)
	{
		// Set up our members.
		window = new Window("No Title", 640, 480);
		manager = new StateManager(window);
	}

	Game::Game(std::string title) : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0)
	{
		window = new Window(title, 640, 480);
		manager = new StateManager(window);
	}

	Game::Game(std::string title, int width, int height, int bpp) : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0)
	{
		window = new Window(title, width, height, bpp);
		manager = new StateManager(window);
	}

	Game::~Game()
	{
		delete manager;
		delete window;
	}

	void Game::setFrameRateCap(bool b)
	{
		capFrameRate = b;
		return;
	}

	bool Game::getFrameRateCap()
	{
		return capFrameRate;
	}

	void Game::setFrameRate(int i)
	{
		framerate = i;
		return;
	}

	float Game::getMaxFrameTime()
	{
		return maxFrameTime;
	}

	float Game::getCappedFrameTime()
	{
		return cappedFrameTime;
	}

	float Game::getMaxFrameRate()
	{
		return 1000 / maxFrameTime;
	}

	float Game::getCappedFrameRate()
	{
		return 1000 / cappedFrameTime;
	}

    void Game::loop()
    {
        while(running)
        {
			frameTimer.start();
            processInput();
            update();
            display();

			// Record the faster time.
			//frameTimer.pause();
			maxFrameTime = (float)(maxFrameTime * .95 + frameTimer.getTime() * .05);
			//frameTimer.unpause();

			// Record the capped time.
			if(capFrameRate && frameTimer.getTime() < 1000 / framerate)
			{
				SDL_Delay((Uint32)(1000 / framerate - frameTimer.getTime()));
				cappedFrameTime = (float)((cappedFrameTime * .95 + frameTimer.getTime() * .05));
			}
        }

        // Clean up afterwards.
        cleanup();
    }
}
