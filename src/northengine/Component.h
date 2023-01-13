#ifndef NORTHENGINE_COMPONENT_H
#define NORTHENGINE_COMPONENT_H

#include <memory>

namespace northengine {

	struct Entity;
	/**
	* Base component class that all components inherit from
	*/
	struct Component
	{
		/**
		* virtual function where you would write functionality that needs to happen every frame
		*/
		virtual void onTick();
		/**
		* virtual function for you to display the component every frame
		*/
		virtual void onDisplay();

		/**
		* Gets a pointer to owning entity 
		* 
		* \return pointer to entity
		*/
		std::shared_ptr<Entity> getEntity() const;


	private:
		friend struct Entity;

		std::weak_ptr<Entity> m_entity;///< pointer to owning entity
		/**
		* tick function that is called every frame
		*/
		void tick(); 
		/**
		* display function that is called every frame
		*/
		void display();

	};
}
#endif