#include "Camera.h"
#include <AL/al.h>
#include <AL/alc.h>
#include "Entity.h"
#include "Transform.h"


namespace northengine  
{
	rend::mat4 Camera::getView()
	{
		return rend::inverse(getEntity()->getTransform()->getModel());
	}
	void Camera::onTick()
	{
		rend::vec3 camPos = getEntity()->getTransform()->getPosition();

		alListener3f(AL_POSITION, camPos.x, camPos.y, camPos.z);
	}
}