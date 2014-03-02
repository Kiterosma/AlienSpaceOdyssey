#ifndef PLATFORMERPLAYER_H
#define PLATFORMERPLAYER_H

#include "Entity.h"

class PlatformerPlayer: public Entity
{
public:
	PlatformerPlayer(Application* a, b2World* w, Vector2f pos);
	virtual list<Entity*> update(float diff);
	virtual void idle();
	virtual ID getID();
	virtual void beginContact(void* other);
	virtual void endContact(void* other);
};

#endif