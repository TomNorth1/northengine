#include "Component.h"
#include "Entity.h"

namespace northengine
{
	void Component::onTick()
	{

	}

	void Component::onDisplay()
	{

	}

	std::shared_ptr<Entity> Component::getEntity() const
	{
		return m_entity.lock();
	}

	void Component::tick()
	{
		onTick();
	}

	void Component::display() 
	{
		onDisplay();
	}
}