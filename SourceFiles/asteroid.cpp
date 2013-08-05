#include "asteroid.h"

Asteroid::Asteroid(Application* a, b2World* w, Vector2f pos, Vector2f vel):Entity(a, w, a->Asteroid,IntRect(0,0,238,174), pos, vel)
{
	sprite.setOrigin(119.f,87.f);
}

list<Entity*> Asteroid::update(float diff)
{
	list<Entity*> result = Entity::update(diff);
	
	sprite.rotate(20.f*diff);

	return result;
}