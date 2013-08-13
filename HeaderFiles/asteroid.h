#ifndef ASTEROID_H
#define ASTEROID_H

#include "entity.h"

class Asteroid: public Entity
{
public:
	Asteroid(Application* a, b2World* w, Vector2f pos, Vector2f vel);
	virtual list<Entity*> update(float diff);
	virtual void beginContact(void* other);
	virtual void endContact(void* other);

protected:

};

#endif