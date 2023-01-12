#include <SDL2/SDL.h>
#include <memory>
#include <vector>


namespace northengine {

	struct Entity;
	struct InputHandler;
	struct Resources;
	
	struct Core
	{
		static std::shared_ptr<Core> initialize();

		void start();
		void stop();

		std::shared_ptr<Entity> addEntity();

		std::shared_ptr<InputHandler> inputHandler;

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

		float getDeltaTime();

		std::shared_ptr<Resources> getResources();

	private:
		std::weak_ptr<Core> m_self;
		bool m_running;

		std::vector<std::shared_ptr<Entity> > m_entities;

		std::shared_ptr<Resources> m_resources;

		SDL_Window* m_window;
		SDL_GLContext m_context;

		float deltaT;
	};
}
