#include "Game.h"

namespace hm
{
	Game::Game() : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0), displayFrameRate(false)
	{
		// Set up our members.
		window = new Window("No Title", 640, 480);
		manager = new StateManager(this, window);
		logger = new Logger();
	}

	Game::Game(std::string title) : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0), displayFrameRate(false)
	{
		this->title = title;
		window = new Window(title, 640, 480);
		manager = new StateManager(this, window);
		logger = new Logger();
	}

	Game::Game(std::string title, int width, int height, int bpp) : capFrameRate(true), framerate(30), frameTimer(), maxFrameTime(0), cappedFrameTime(0), displayFrameRate(false)
	{
		this->title = title;
		window = new Window(title, width, height, bpp);
		manager = new StateManager(this, window);
		logger = new Logger();
	}

	Game::~Game()
	{
		delete manager;
		manager = NULL;
		delete window;
		window = NULL;
		delete logger;
		logger = NULL;
	}

	void Game::setCapFrameRate(bool b)
	{
		capFrameRate = b;
		return;
	}

	bool Game::frameRateIsCapped()
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
		// Frame Rate = 1000ms / Time Spent per Frame
		return 1000 / maxFrameTime;
	}

	float Game::getCappedFrameRate()
	{
		// Frame Rate = 1000ms / Time Spent per Frame
		return 1000 / cappedFrameTime;
	}

	float Game::getFrameRate()
	{
		if(frameRateIsCapped())
			return 1000 / cappedFrameTime;
		else
			return 1000 / maxFrameTime;
	}

	void Game::frameRateView(bool b)
	{
		displayFrameRate = b;
		if(!b) // Need to change back to just title.
			window->setTitle(title);
		return;
	}

	void Game::log(std::string msg, LogLevel level)
	{
		logger->log(msg, level);
	}

	void Game::quit()
	{
		if(running)
			running = false;
		else
			std::cout << "Game is not running. quit() has no effect." << std::endl;
		return;
	}

	StateManager* Game::getStateManager()
	{
		return manager;
	}

    void Game::loop()
    {
		running = true;

		Timer titleDisplayTimer;
		titleDisplayTimer.start();
       	while(running && manager->getCurrentState() != NULL)
       	{
			frameTimer.start();
        	processInput();
        	update();
        	display();

			// Record the faster time.
			frameTimer.pause();
			maxFrameTime = (float)(maxFrameTime * .995 + frameTimer.getTime() * .005);
			frameTimer.unpause();

			// Record the capped time.
			if(capFrameRate)
			{
				if(titleDisplayTimer.getTime() >= 1000 && displayFrameRate)
				{
					// Show framerate in title.
					std::string s = title + " @ " + std::to_string(framerate) + "fps";
					window->setTitle(s);
					titleDisplayTimer.reset();
				}

				if(frameTimer.getTime() < 1000 / framerate)
					SDL_Delay((Uint32)(1000 / framerate - frameTimer.getTime()));
				cappedFrameTime = (float)((cappedFrameTime * .995 + frameTimer.getTime() * .005));
			}
        }

        // Clean up afterwards.
        cleanup();
    }

	bool Game::initSdl()
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			logger->log("SDL initialization failed.", hm::ERROR);
			return false;
		}
		return true;
	}
	
	bool Game::initSdlImage()
	{
		int flags = IMG_INIT_JPG | IMG_INIT_PNG;
		int initted = IMG_Init(flags);
		if((initted&flags) != flags)
		{
			logger->log("SDL_image initialization failed.", hm::ERROR);
			logger->log(IMG_GetError(), hm::ERROR);
			return false;
		}
		return true;
	}
	
	bool Game::initSdlMixer()
	{
		int flags = MIX_INIT_MP3 | MIX_INIT_OGG;
		int initted = Mix_Init(flags);
		if((initted&flags) != flags)
		{
			logger->log("SDL_mixer initialization failed.", hm::ERROR);
			logger->log(Mix_GetError(), hm::ERROR);
			return false;
		}
		return true;
	}
	
	bool Game::initSdlTtf()
	{
		if(TTF_Init() == -1)
		{
			logger->log("SDL_ttf initialization failed.", hm::ERROR);
			logger->log(TTF_GetError(), hm::ERROR);
			return false;
		}
		return true;
	}
}
