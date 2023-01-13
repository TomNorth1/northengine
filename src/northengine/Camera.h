#include "Component.h"
#include "rend/rend.h"

namespace northengine{
	/**
	* Camera component where you can get the view matrix
	*/
	struct Camera : Component
	{
		/** Generate view matrix from cameras transform component.
		* 
		* \return The generated view matrix
		*/
		rend::mat4 getView();
		/**
		* update audio listener position
		*/
		void onTick();
	};

}