#include <northengine/northengine.h>

#include <iostream>

using namespace northengine;

struct Player : Component
{
	Player() : m_angle(0)
	{
		
	}

	void onTick()
	{
		m_angle += 45.f * getEntity()->getCore()->getDeltaTime();

		getEntity()->getTransform()->setRotation(rend::vec3(0, m_angle, 0));

		rend::vec3 oldPos = getEntity()->getTransform()->getPosition();
		getEntity()->getTransform()->setPosition(oldPos + velocity * getEntity()->getCore()->getDeltaTime());

	}

	void moveForwardPressed() 
	{
		velocity.z = 10.f;
	}

	void moveForwardReleased() 
	{
		velocity.z = 0.0f;
	}

	void moveBackwardPressed()
	{
		velocity.z = -10.f;
		
	}
	void moveBackwardReleased() 
	{
		velocity.z = 0.0f;
	}
private:
	float m_angle;
	rend::vec3 velocity;
};


std::shared_ptr<Player> p;

void upArrow()
{
	p->moveForwardPressed();
}

void upArrowReleased()
{
	p->moveForwardReleased();
}

void downArrow()
{
	p->moveBackwardPressed();
}
void downArrowReleased() 
{
	p->moveBackwardReleased();
}

int main(int argc, char *argv[])
{
	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> e = core->addEntity();
	p = e->addComponent<Player>();
	std::shared_ptr<MeshRenderer> mr;
	mr = e->addComponent<MeshRenderer>();
	mr->init("data/textures/Whiskers_diffuse.png", "data/models/curuthers.obj");
	e->getTransform()->setPosition(rend::vec3(0, 0, -15));
	std::shared_ptr<BoxCollider> bc = e->addComponent<BoxCollider>();
	bc->setSize(rend::vec3(1, 1, 1));
	e->addComponent<RigidBody>();

	std::shared_ptr<Entity> other = core->addEntity();
	std::shared_ptr<MeshRenderer> mr2;
	mr2 = other->addComponent<MeshRenderer>();
	mr2->init("data/textures/Whiskers_diffuse.png", "data/models/curuthers.obj");
	other->getTransform()->setPosition(rend::vec3(0, 0, -20));
	std::shared_ptr<BoxCollider> bc_other = other->addComponent<BoxCollider>();
	bc_other->setSize(rend::vec3(1, 1, 1));

	core->inputHandler->addBinding(SDLK_UP, &upArrow, &upArrowReleased);
	core->inputHandler->addBinding(SDLK_DOWN, &downArrow, &downArrowReleased);
	
	core->start();

	return 0;
}

