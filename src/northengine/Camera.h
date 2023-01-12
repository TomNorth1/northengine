#include "Component.h"
#include "rend/rend.h"

namespace northengine{

	struct Camera : Component
	{
		rend::mat4 getView();
		void onTick();
	};

}