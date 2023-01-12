#ifndef NORTHENGINE_COMPONENT_H
#define NORTHENGINE_COMPONENT_H

#include <memory>

namespace northengine {

	struct Entity;

	struct Component
	{
		virtual void onTick();
		virtual void onDisplay();

		std::shared_ptr<Entity> getEntity() const;


	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;

		void tick();
		void display();

	};
}
#endif