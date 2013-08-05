#ifndef OVERHEADPLAYER_H
#define OVERHEADPLAYER_H

#include "entity.h"
#include "projectile.h"

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

private:

};

#endif