#include "Game.h"

namespace hm
{
	Game::Game() : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		window = new Window();
		manager = new StateManager(this, window);
	}

	Game::Game(std::string title) : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		this->title = title;
		WindowSettings ws;
		ws.setBestFullscreenMode();
		ws.setTitle(title);
		window = new Window(ws);
		manager = new StateManager(this, window);
	}

	Game::Game(std::string title, unsigned int width, unsigned int height, bool fs) : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		this->title = title;
		WindowSettings ws;
		ws.setTitle(title);
		ws.setResolution({ width, height });
		ws.useFullscreen(fs);
		window = new Window(ws);
		manager = new StateManager(this, window);
	}

	Game::~Game()
	{
		delete manager;
		manager = NULL;
		delete window;
		window = NULL;
	}

	void Game::capFrameRate(bool b)
	{
		cap_frame_rate = b;
		return;
	}

	bool Game::frameRateIsCapped()
	{
		return cap_frame_rate;
	}

	void Game::setFrameRate(int i)
	{
		framerate = i;
		return;
	}

	float Game::getFrameRate()
	{
		if(cap_frame_rate)
			return framerate;
		else
			return 0;
	}

	void Game::log(std::string msg, LogLevel level)
	{
		Logger::getLogger()->log(msg, level);
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
			if(manager->hasState())	// It is possible for the state to
        		display();			// have popped itself during update().

			// Record the capped time.
			if(cap_frame_rate)
			{
				if(frameTimer.getTime() < (1000 / framerate))
					SDL_Delay((Uint32)(1000 / framerate - frameTimer.getTime()));
			}
        }

        // Clean up afterwards.
        cleanup();
    }
	
	void Game::SDLInit()
	{
		if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		{
			log("SDL initialization failed.", hm::ERROR);
			log(SDL_GetError(), hm::ERROR);
		}
		
		int flags = IMG_INIT_JPG | IMG_INIT_PNG;
		int initted = IMG_Init(flags);
		if((initted&flags) != flags)
		{
			log("SDL_image initialization failed.", hm::ERROR);
			log(IMG_GetError(), hm::ERROR);
		}
		
		flags = MIX_INIT_MP3 | MIX_INIT_OGG;
		initted = Mix_Init(flags);
		if((initted&flags) != flags)
		{
			log("SDL_mixer initialization failed.", hm::ERROR);
			log(Mix_GetError(), hm::ERROR);
		}
		
		if(TTF_Init() == -1)
		{
			log("SDL_ttf initialization failed.", hm::ERROR);
			log(TTF_GetError(), hm::ERROR);
		}
		
		return;
	}
	
	void Game::SDLQuit()
	{
		SDL_Quit();
		IMG_Quit();
		Mix_Quit();
		TTF_Quit();
		
		return;
	}
}
