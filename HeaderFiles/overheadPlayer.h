#ifndef OVERHEADPLAYER_H
#define OVERHEADPLAYER_H

#include "Projectile.h"

class OverheadPlayer: public Entity
{
public:
	OverheadPlayer(Application* a, b2World* w, Vector2f pos);
	virtual list<Entity*> update(float diff);
	virtual void idle();

protected:
	const float speedLimit;
	float cooldown;

	void decelerateX();
	void decelerateY();
	Projectile* shoot();
	virtual void accelerateCenter(b2Vec2 force);
	virtual float angleToMouse();
	virtual void orientPlayer();
	virtual ID getID();
	virtual void beginContact(void* other);
	virtual void endContact(void* other);

private:

};

#endif