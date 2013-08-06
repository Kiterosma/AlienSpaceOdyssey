#ifndef ENTITY_H
#define ENTITY_H

#include "gameObject.h"
#include "application.h"
#include "sfmlb2d.h"

class Entity: public GameObject
{
public:
	Entity(Application* a, b2World* w, Texture & t, IntRect rect, Vector2f pos, Vector2f vel);
	virtual void draw();
	virtual void setTexture(Texture & t);
	virtual void setRect(IntRect rect);
	virtual b2Vec2 getVelocity();
	virtual void setVelocity(b2Vec2 vel);
	virtual b2Vec2 getPositionMeters();
	virtual Vector2f getPositionPixels();
	virtual list<Entity*> update(float diff);
	virtual void accelerateCenter(b2Vec2 force);
	virtual void idle();
	virtual void rotate(float angle);

	bool despawn;

protected:
	Sprite sprite;
	b2Body* body;

private:

};

#endif