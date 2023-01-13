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
		//m_angle += 45.f * getEntity()->getCore()->getDeltaTime();

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

	void moveRightPressed()
	{
		velocity.x = 10.f;
	}
	void moveRightReleased() 
	{
		velocity.x = 0.0f;
	}
	void moveLeftPressed() 
	{
		velocity.x = -10.f;
	}
	void moveLeftReleased() 
	{
		velocity.x = 0.0f;
	}
private:
	float m_angle;
	rend::vec3 velocity;
};


std::shared_ptr<Player> p;
std::shared_ptr<AudioSource> hornPlayer;

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
void leftArrowPressed() 
{
	p->moveLeftPressed();
}

void leftArrowReleased() 
{
	p->moveLeftReleased();
}

void rightArrowPressed() 
{
	p->moveRightPressed();
}

void rightArrowReleased() 
{
	p->moveRightReleased();
}

void spaceBarPressed() 
{
	hornPlayer->play();
}
void spaceBarReleased()
{

}



int main(int argc, char *argv[])
{
	std::shared_ptr<Core> core = Core::initialize();
	
	std::shared_ptr<Entity> e = core->addEntity();
	p = e->addComponent<Player>();
	std::shared_ptr<MeshRenderer> mr;
	mr = e->addComponent<MeshRenderer>();
	mr->setResources("data/textures/Whiskers_diffuse.png", "data/models/curuthers.obj");
	e->getTransform()->setPosition(rend::vec3(0, 0, -15));
	std::shared_ptr<BoxCollider> bc = e->addComponent<BoxCollider>();
	bc->setSize(rend::vec3(1, 1, 1));
	e->addComponent<RigidBody>();
	hornPlayer = e->addComponent<AudioSource>();
	hornPlayer->setAudioClip(core->getResources()->load<AudioClip>("data/audio/dixie_horn.ogg"));

	std::shared_ptr<Entity> other = core->addEntity();
	std::shared_ptr<MeshRenderer> mr2;
	mr2 = other->addComponent<MeshRenderer>();
	mr2->setResources("data/textures/Whiskers_diffuse.png", "data/models/curuthers.obj");
	std::shared_ptr<AudioSource> as = other->addComponent<AudioSource>();
	as->setAudioClip(core->getResources()->load<AudioClip>("data/audio/dixie_horn.ogg"));
	other->getTransform()->setPosition(rend::vec3(4, 0, -20));
	std::shared_ptr<BoxCollider> bc_other = other->addComponent<BoxCollider>();
	bc_other->setSize(rend::vec3(1, 1, 1));
	as->play();

	std::shared_ptr<Entity> camera = core->addEntity();
	camera->addComponent<Camera>();
	camera->getTransform()->setPosition(rend::vec3(0,0,20));
	camera->getTransform()->setRotation(rend::vec3(0,0,0));

	std::shared_ptr<Entity> floor = core->addEntity();
	std::shared_ptr<MeshRenderer> fr;
	fr = floor->addComponent<MeshRenderer>();
	fr->setResources("data/textures/wood.png", "data/models/floor.obj");
	std::shared_ptr<BoxCollider> bc_floor = floor->addComponent<BoxCollider>();
	bc_floor->setSize(rend::vec3(100, 1, 100));

	std::shared_ptr<Entity> cube = core->addEntity();
	std::shared_ptr<MeshRenderer> cr;
	cr = cube->addComponent<MeshRenderer>();
	cr->setResources("data/textures/crate0_diffuse.png", "data/models/cube.obj");
	std::shared_ptr<BoxCollider> bc_cube = cube->addComponent<BoxCollider>();
	bc_cube->setSize(rend::vec3(2, 2, 2));
	cube->getTransform()->setPosition(rend::vec3(-5,-0.9,5));


	core->inputHandler->addBinding(SDLK_UP, &upArrow, &upArrowReleased);
	core->inputHandler->addBinding(SDLK_DOWN, &downArrow, &downArrowReleased);
	core->inputHandler->addBinding(SDLK_LEFT, &leftArrowPressed, &leftArrowReleased);
	core->inputHandler->addBinding(SDLK_RIGHT, &rightArrowPressed, &rightArrowReleased);
	core->inputHandler->addBinding(SDLK_SPACE, &spaceBarPressed, &spaceBarReleased);
	core->inputHandler->addBinding(SDLK_w, &upArrow, &upArrowReleased);
	core->inputHandler->addBinding(SDLK_s, &downArrow, &downArrowReleased);
	core->inputHandler->addBinding(SDLK_a, &leftArrowPressed, &leftArrowReleased);
	core->inputHandler->addBinding(SDLK_d, &rightArrowPressed, &rightArrowReleased);
	
	core->start();

	return 0;
}

