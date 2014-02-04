#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile: public Entity
{
public:
	enum Type{Laser};
	Projectile(Application* a, b2World* w, Vector2f pos, Vector2f vel,float angle, Type type);
	virtual list<Entity*> update(float diff);
	virtual void beginContact(void* other);
	virtual void endContact(void* other);
	virtual ID getID();

protected:
	const float speed;
	Sound sound;
	float deathTimer;

private:

};

#endif