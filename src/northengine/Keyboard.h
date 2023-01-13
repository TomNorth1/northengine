#include "SDL2/SDL.h"
#include <vector>
#include <functional>
#include <memory>
#include "Component.h"
namespace northengine 
{
	/**
	* binds a key to a pressed and released function
	*/
	struct KeyBinding 
	{
		/**
		* default constructor
		* 
		* \param _key the SDLKeycode you want to create a binding for
		* \param _funcDown the function to call when key is pressed
		* \param _funcUp the function to call when key is released
		*/
		KeyBinding(SDL_Keycode _key, std::function<void()> _funcDown , std::function<void()> _funcUp);


		SDL_Keycode getKey();
		void callDownFunc();
		void callUpFunc();
	private:
		SDL_Keycode m_key;
		std::function<void()> m_funcDown;
		std::function<void()> m_funcUp;
	};
		

	/**
	* class that is responsible for creating key binds and handling input events
	*/
	struct InputHandler
	{
		/**
		* creates a new keybinding object
		* 
		* \param _key the SDLKeycode you want to create a binding for
		* \param _funcDown the function to call when key is pressed
		* \param _funcUp the function to call when key is released
		*/
		void addBinding(SDL_Keycode _key, std::function<void()> _funcDown, std::function<void()> _funcUp);
		/**
		* handles all key down events
		* 
		* \param SDL event
		*/
		void handleKeyDownEvent(SDL_Event &e);
		/**
		* handles all key up events
		* 
		* \param SDL event
		*/
		void handleKeyUpEvent(SDL_Event &e);

	private:
		std::vector<std::shared_ptr<KeyBinding>> m_bindings;///< vector of all keybindings
	};
}
