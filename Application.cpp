// Hume Library Version 0.6 

#include "Application.h"

namespace hm
{
	Application::Application() : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		window = new Window();
		manager = new StateManager(this, window);
	}

	Application::Application(const std::string& title) : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		this->title = title;
		WindowSettings ws;
		ws.setBestFullscreenMode();
		ws.title = title;
		window = new Window(ws);
		manager = new StateManager(this, window);
	}

	Application::Application(const std::string& title, const unsigned int width, const unsigned int height, const bool fs) : cap_frame_rate(true), framerate(60), frameTimer()
	{
		SDLInit();
		this->title = title;
		WindowSettings ws;
		ws.title = title;
		ws.resolution.width = width;
		ws.resolution.height = height;
		ws.fullscreen = fs;
		window = new Window(ws);
		manager = new StateManager(this, window);
	}

	Application::~Application()
	{
		delete manager;
		manager = NULL;
		delete window;
		window = NULL;
	}

	void Application::capFrameRate(const bool b)
	{
		cap_frame_rate = b;
		return;
	}

	bool Application::frameRateIsCapped() const
	{
		return cap_frame_rate;
	}

	void Application::setFrameRate(const unsigned int i)
	{
		framerate = i;
		return;
	}

	float Application::getFrameRate() const
	{
		if(cap_frame_rate)
			return framerate;
		else
			return 0;
	}

	void Application::log(const std::string& msg, const LogLevel level) const
	{
		Logger::getLogger()->log(msg, level);
	}

	void Application::quit()
	{
		if(running)
			running = false;
		else
			std::cout << "Application is not running. quit() has no effect." << std::endl;
		return;
	}

	StateManager* Application::getStateManager() const
	{
		return manager;
	}

    void Application::loop()
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
	
	void Application::SDLInit() const
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
		
		if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		{
			log("SDL_mixer initialization failed.", hm::ERROR);
			log(Mix_GetError());
		}
		
		if(TTF_Init() == -1)
		{
			log("SDL_ttf initialization failed.", hm::ERROR);
			log(TTF_GetError(), hm::ERROR);
		}
		
		return;
	}
	
	void Application::SDLQuit() const
	{
		SDL_Quit();
		IMG_Quit();
		Mix_Quit();
		TTF_Quit();
		
		return;
	}
}
