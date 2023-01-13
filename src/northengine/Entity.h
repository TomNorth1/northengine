#include <memory>
#include <vector>

namespace northengine
{
	struct Core;
	struct Component;
	struct Transform;

	/**
	* Base entity class. Every game object should be of type Entity 
	*/
	struct Entity
	{

		/**
		* Adds component of type T to m_components.
		* 
		* \return pointer to new component
		*/
		template <typename T>
		std::shared_ptr<T> addComponent() 
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			m_components.push_back(rtn);

			return rtn;
		}
		/**
		* Gets a pointer the parenting core object.
		* 
		* \return Pointer to core
		*/
		std::shared_ptr<Core> getCore();

		/**
		* Gets a pointer to the transform component that every entity has as default.
		* 
		* \return pointer to Transform component
		*/
		std::shared_ptr<Transform> getTransform();

	private:
		friend struct Core;
		
		std::weak_ptr<Core> m_core;///< pointer to core object
		std::weak_ptr<Entity> m_self;///< pointer to self to pass down to components

		bool m_alive;///< stores state of the entity
		std::vector<std::shared_ptr<Component>> m_components;///< vector of components attached to the entity

		std::weak_ptr<Transform> m_transform; ///< pointer to the transform component of this entity

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