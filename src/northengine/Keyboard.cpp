#include "Keyboard.h"
#include <iostream>

namespace northengine
{
	void InputHandler::addBinding(SDL_Keycode _key, std::function<void()> _funcDown, std::function<void()> _funcUp)
	{
		std::shared_ptr<KeyBinding>newBinding = std::make_shared<KeyBinding>(_key, _funcDown, _funcUp);
		m_bindings.push_back(newBinding);
	}

	void InputHandler::handleKeyDownEvent(SDL_Event &e)
	{
		for (size_t bi = 0; bi < m_bindings.size(); bi++)
		{
			if (m_bindings.at(bi)->getKey() == e.key.keysym.sym)
			{
				m_bindings.at(bi)->callDownFunc();
			}
		}

	}

	void InputHandler::handleKeyUpEvent(SDL_Event &e)
	{
		for (size_t bi = 0; bi < m_bindings.size(); bi++)
		{
			if (m_bindings.at(bi)->getKey() == e.key.keysym.sym)
			{
				m_bindings.at(bi)->callUpFunc();
			}
		}
	}

	KeyBinding::KeyBinding(SDL_Keycode _key, std::function<void()> _funcDown, std::function<void()> _funcUp)
	{
		m_key = _key;
		m_funcDown = _funcDown;
		m_funcUp = _funcUp;
	}

	SDL_Keycode KeyBinding::getKey()
	{
		return m_key;
	}
	void KeyBinding::callDownFunc()
	{
		m_funcDown();
	}
	void KeyBinding::callUpFunc()
	{
		m_funcUp();
	}
}