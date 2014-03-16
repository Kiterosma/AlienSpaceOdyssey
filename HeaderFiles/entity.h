#ifndef ENTITY_H
#define ENTITY_H

#include "Application.h"
#include "sfmlb2d.h"

#define PIXELS_PER_METER 100.f;
#define DEG_TO_RAD .01745f;

class Entity: public GameObject
{
public:

	enum ID{default, overheadplayer, platformerplayer, asteroid, projectile};

	virtual ~Entity();
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
	virtual void beginContact(void* other)=0;
	virtual void endContact(void* other)=0;
	virtual void damage(int amount);
	virtual ID getID();
	virtual void contactGround();
	virtual void jump(float speed, float cooldown);

	bool despawn;

protected:
	Sprite sprite;
	b2Body* body;
	int health;
	bool doDraw;
	bool canJump;
	float jumpCooldown;

private:

};

#endif