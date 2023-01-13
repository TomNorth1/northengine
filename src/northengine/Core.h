#include <SDL2/SDL.h>
#include <memory>
#include <vector>


namespace northengine {

	struct Entity;
	struct InputHandler;
	struct Resources;
	struct Camera;
	

	/**
	* Main core of our engine. Will hold list of all entities annd resources our game needs as being in charge of the main game loop.
	*/
	struct Core
	{
		/**
		* Creates core object. Initializes member variables of core, setup SDL_Window and audio.
		* 
		* \return A shared ptr to the core 
		*/
		static std::shared_ptr<Core> initialize();


		/**
		* Starts the core game loop and enables ticking and updating of entities.
		*/
		void start();

		/**
		* Stops the core game loop.
		*/
		void stop();

		/**
		* Adds a new entity to the m_entities vector.
		* 
		* \return Pointer to the new entity
		*/
		std::shared_ptr<Entity> addEntity();


		
		std::shared_ptr<InputHandler> inputHandler; ///< InputHandler to handle all of your games input

		/**
		* Template function to find all the components of a specified type T
		* 
		* \param _out the output list of components
		*/
		template <typename T>
		void find(std::vector<std::shared_ptr<T>>& _out) 
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei) 
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);
				for (size_t ci = 0; ci < e->m_components.size(); ++ci) 
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);
					
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);

					if (t) 
					{
						_out.push_back(t);
					}
				}
			}
		}


		/**
		* Gets the time between this frame and last frame.
		* 
		* \return DeltaTime as a float
		*/
		float getDeltaTime();


		/**
		* Gets the resources member variable.
		* 
		* \return ptr to m_resources
		*/
		std::shared_ptr<Resources> getResources();

	private:
		std::weak_ptr<Core> m_self;///< pointer to self to pass down to new entities that are added to core
		bool m_running;///< status of the core loop

		std::vector<std::shared_ptr<Entity> > m_entities; ///< vector of all entities currently in your game

		std::shared_ptr<Resources> m_resources;///< resource manager

		SDL_Window* m_window;///< SDL window
		SDL_GLContext m_context;///< SDL context

		float deltaT;///< Delta time (time between this frame and last frame) 
	};
}
