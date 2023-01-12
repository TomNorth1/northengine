#include "Component.h"
#include "rend/rend.h"

namespace northengine 
{
	struct RigidBody : Component
	{
		void onTick();

	private:
		rend::vec3 lastSafePos;
	};
}