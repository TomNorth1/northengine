#include "Core.h"
#include "Entity.h"
#include "Transform.h"
#include "Keyboard.h"
#include "Resources.h"
#include "AL/al.h"
#include <AL/alc.h>

#include "rend/rend.h"

#include <stdexcept>

namespace northengine {


	std::shared_ptr<Core> northengine::Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->inputHandler = std::make_shared<InputHandler>();

		rtn->m_resources = std::make_shared<Resources>();

		rtn->m_self = rtn;
		rtn->m_running = false;

		if (SDL_Init(SDL_INIT_VIDEO) < 0) 
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		rtn->m_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!rtn->m_window) 
		{
			throw std::runtime_error("Failed to create window");
		}

		rtn->m_context = SDL_GL_CreateContext(rtn->m_window);

		if (!rtn->m_context) 
		{
			throw std::runtime_error("Failed to create context");
		}

		/*
		INITIALISE AUDIO
		*/
		ALCdevice* device = alcOpenDevice(NULL);

		if (!device)
		{
			throw std::runtime_error("Failed to open audio device");
		}

		ALCcontext* context = alcCreateContext(device, NULL);

		if (!context)
		{
			alcCloseDevice(device);
			throw std::runtime_error("Failed to create audio context");
		}

		if (!alcMakeContextCurrent(context))
		{
			alcDestroyContext(context);
			alcCloseDevice(device);
			throw std::runtime_error("Failed to make context current");
		}

		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);

		return rtn;
	}

	void Core::start() 
	{
		m_running = true;
		SDL_Event event = {0};

		std::vector<std::shared_ptr<InputHandler>> inputHandles;
		find(inputHandles);
		
		unsigned int lastTime = SDL_GetTicks();
		while (m_running) 
		{
			
			while (SDL_PollEvent(&event)) 
			{
				if (event.type == SDL_QUIT) 
				{
					m_running = false;
				}

				if (event.type == SDL_KEYDOWN) 
				{
					inputHandler->handleKeyDownEvent(event);
					
				}
				if (event.type == SDL_KEYUP) 
				{
					inputHandler->handleKeyUpEvent(event);
				}

			}

			for (size_t ei = 0; ei < m_entities.size(); ei++) 
			{
				m_entities.at(ei)->tick();
			}

			rend::Renderer r(1280, 720);
			r.clear();

			for (size_t ei = 0; ei < m_entities.size(); ei++) 
			{
				m_entities.at(ei)->display();
			}

			SDL_GL_SwapWindow(m_window);

			unsigned int currentTime = SDL_GetTicks();

			deltaT = float(currentTime - lastTime) / 1000.0f;
			lastTime = currentTime;

			if (deltaT < (1.0f / 50.0f))
			{
				SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaT) * 1000.0f));
			}
		}
	}
	void Core::stop() 
	{
		m_running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;
		rtn->m_transform = rtn->addComponent<Transform>();

		m_entities.push_back(rtn);

		return rtn;
	}
	float Core::getDeltaTime()
	{
		return deltaT;
	}
	std::shared_ptr<Resources> Core::getResources()
	{
		return m_resources;
	}
}