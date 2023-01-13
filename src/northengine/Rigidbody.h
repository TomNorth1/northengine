#include "Component.h"
#include "rend/rend.h"

namespace northengine 
{
	/**
	* Component that handles collision responses
	*/
	struct RigidBody : Component
	{
		/**
		* check if we are colliding with another object if we are it calls the collision response function 
		*/
		void onTick();

	private:
		rend::vec3 lastSafePos;///< last known position where owning entity is not colliding with anything
	};
}