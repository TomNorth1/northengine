#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace northengine 
{
    bool BoxCollider::colliding(const BoxCollider& _other)
    {
		rend::vec3 a = getEntity()->getTransform()->getPosition();
		rend::vec3 b = _other.getEntity()->getTransform()->getPosition();
		rend::vec3 ahs = m_size / 2.0f;
		rend::vec3 bhs = _other.m_size / 2.0f;

		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;
				
			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
			{
				return false;
			}
		}
		return true;
    }

	bool BoxCollider::colliding(rend::vec3 position, rend::vec3 size)
	{
		rend::vec3 a = getEntity()->getTransform()->getPosition();
		rend::vec3 b = position;
		rend::vec3 ahs = m_size / 2.0f;
		rend::vec3 bhs = size / 2.0f;

		if (a.x > b.x)
		{
			if (b.x + bhs.x < a.x - ahs.x)
			{
				return false;

			}
		}
		else
		{
			if (a.x + ahs.x < b.x - bhs.x)
			{
				return false;
			}
		}
		if (a.y > b.y)
		{
			if (b.y + bhs.y < a.y - ahs.y)
			{
				return false;
			}
		}
		else
		{
			if (a.y + ahs.y < b.y - bhs.y)
			{
				return false;
			}
		}
		if (a.z > b.z)
		{
			if (b.z + bhs.z < a.z - ahs.z)
			{
				return false;
			}
		}
		else
		{
			if (a.z + ahs.z < b.z - bhs.z)
			{
				return false;
			}
		}
		return true;
	}

	rend::vec3 BoxCollider::getCollisionResponse(rend::vec3 position, rend::vec3 size)
	{
		float amount = 0.1f;
		float step = 0.1f;

		while (colliding(position, size))
		{
			if (!colliding(position, size)) break;
			position.x += amount;
			if (!colliding(position, size)) break;
			position.x -= amount;
			position.x -= amount;
			if (!colliding(position, size)) break;
			position.x += amount;
			position.z += amount;
			if (!colliding(position, size)) break;
			position.z -= amount;
			position.z -= amount;
			if (!colliding(position, size)) break;
			position.z += amount;
			position.y += amount;
			if (!colliding(position, size)) break;
			position.y -= amount;
			position.y -= amount;
			if (!colliding(position, size)) break;
			position.y += amount;
			amount += step;
		}
		return position;
	}

    void BoxCollider::setOffset(rend::vec3 _offset)
    {
        m_offset = _offset;
    }

	rend::vec3 BoxCollider::getSize()
	{
		return m_size;
	}

    void BoxCollider::setSize(rend::vec3 _size)
    {
        m_size = _size;
    }
}