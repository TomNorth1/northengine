#include "Component.h"
#include "rend/rend.h"

namespace northengine
{
	struct BoxCollider : Component 
	{
		bool colliding(const BoxCollider& _other);
		bool colliding(rend::vec3 position, rend::vec3 size);

		rend::vec3 getCollisionResponse(rend::vec3 position, rend::vec3 size);

		void setSize(rend::vec3 _size);
		void setOffset(rend::vec3 _offset);

		rend::vec3 getSize();
	private:
		rend::vec3 m_size;
		rend::vec3 m_offset;
	};
}