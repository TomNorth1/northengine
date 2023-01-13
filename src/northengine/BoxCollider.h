#include "Component.h"
#include "rend/rend.h"

namespace northengine
{
	/**
	* Simple box collider component
	*/
	struct BoxCollider : Component 
	{

		/**
		* checks if owning entity is colliding with the _other BoxCollider
		* 
		* \param _other other BoxCollider component
		*/
		bool colliding(const BoxCollider& _other);
		/**
		* checks if owning entity is colliding with the _other BoxCollider
		*
		* \param position Positiion of other BoxCollider component
		* \param size Size of the other BoxCollider component
		*/
		bool colliding(rend::vec3 position, rend::vec3 size);


		/**
		* basic kludge collision response
		* 
		* \param position Positiion of other BoxCollider component
		* \param size Size of the other BoxCollider component
		*/
		rend::vec3 getCollisionResponse(rend::vec3 position, rend::vec3 size);

		void setSize(rend::vec3 _size);
		void setOffset(rend::vec3 _offset);

		rend::vec3 getSize();
	private:
		rend::vec3 m_size;///< size of the BoxCollider
		rend::vec3 m_offset;///< offset position of BoxCollider
	};
}