#include "Entity.h"
#include "Component.h"

namespace northengine
{
	std::shared_ptr<Core> Entity::getCore()
	{
		return m_core.lock();
	}
	std::shared_ptr<Transform> Entity::getTransform()
	{
		return m_transform.lock();
	}
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}
	}

	void Entity::display() 
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->display();
		}
	}
}