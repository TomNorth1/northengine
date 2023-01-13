#include "Component.h"

#include <rend/rend.h>

namespace northengine 
{
	/**
	* Component providing position information of the entity
	*/
	struct Transform : Component 
	{
		/**
		* defualt constructor to make sure scale isnt 0
		*/
		Transform();

		/**
		* Generate the model matrix based on the position, rotation and
		* scale.
		*
		* \return The generated model matrix
		*/
		rend::mat4 getModel();

		void setPosition(const rend::vec3& _position);
		void setRotation(const rend::vec3& _rotation);
		void setScale(const rend::vec3& _scale);

		rend::vec3 getPosition();
		rend::vec3 getRotation();
		rend::vec3 getScale();

	private:
		rend::vec3 m_position; ///< X, Y, Z location of Entity
		rend::vec3 m_rotation; ///< Rotation of Entity in euler angles
		rend::vec3 m_scale; ///< Scale of Entity
	};
}