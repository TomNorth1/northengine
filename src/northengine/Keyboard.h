#include "SDL2/SDL.h"
#include <vector>
#include <functional>
#include <memory>
#include "Component.h"
namespace northengine 
{
	struct KeyBinding 
	{
		KeyBinding(SDL_Keycode _key, std::function<void()> _funcDown , std::function<void()> _funcUp);

		SDL_Keycode getKey();
		void callDownFunc();
		void callUpFunc();
	private:
		SDL_Keycode m_key;
		std::function<void()> m_funcDown;
		std::function<void()> m_funcUp;
	};
		


	struct InputHandler
	{
		void addBinding(SDL_Keycode _key, std::function<void()> _funcDown, std::function<void()> _funcUp);
		void handleKeyDownEvent(SDL_Event &e);
		void handleKeyUpEvent(SDL_Event &e);

	private:
		std::vector<std::shared_ptr<KeyBinding>> m_bindings;
	};
}
