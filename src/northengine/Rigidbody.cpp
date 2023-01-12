#include "Rigidbody.h"
#include <vector>
#include "BoxCollider.h"
#include "Entity.h"
#include "Core.h"
#include <memory>
#include <iostream>
#include "Transform.h"


namespace northengine
{
	void RigidBody::onTick() 
	{
		std::vector<std::shared_ptr<BoxCollider>> colliders;

		getEntity()->getCore()->find(colliders);

		std::vector<std::shared_ptr<BoxCollider>>::iterator it;

		for (size_t ci = 0; ci < colliders.size(); ++ci) 
		{
			std::vector<std::shared_ptr<BoxCollider>> otherColliders = colliders;

			std::shared_ptr<BoxCollider> bc = colliders.at(ci);

			for (size_t ck =0; ck < colliders.size(); ++ck) 
			{
				if (bc->getEntity() != colliders.at(ck)->getEntity())
				{
					if (bc->colliding(*colliders.at(ck)))
					{
						if (rend::distance(bc->getCollisionResponse(colliders.at(ck)->getEntity()->getTransform()->getPosition(), colliders.at(ck)->getSize()), lastSafePos) > 0.5f)
						{
							getEntity()->getTransform()->setPosition(lastSafePos);
						}
						else 
						{
							getEntity()->getTransform()->setPosition(bc->getCollisionResponse(colliders.at(ck)->getEntity()->getTransform()->getPosition(), colliders.at(ck)->getSize()));
						}
					}
					else 
					{
						lastSafePos = getEntity()->getTransform()->getPosition();
					}
				}
			}
		}
	}
}