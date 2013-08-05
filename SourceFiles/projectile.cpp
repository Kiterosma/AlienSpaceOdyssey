#include "projectile.h"

/*
Angle for contructor is in radians
*/
Projectile::Projectile(Application* a, b2World* w, Vector2f pos, Vector2f vel, float angle, Type type):sound(a->OUGH),speed(20.f),Entity(a, w, a->LaserSprite, IntRect(0,0,290,74), pos, vel + Vector2f(20*std::cosf(angle),20*std::sinf(angle)))
{
	deathTimer = 5.f;

	sprite.setOrigin(0,37.f);
	sprite.rotate((angle/(2*3.1416f))*360);
	sprite.scale(.1f,.1f);

	sound.play();
}

list<Entity*> Projectile::update(float diff)
{
	list<Entity*> result = Entity::update(diff);

	deathTimer -= diff;
	if(deathTimer<0)
	{
		despawn = true;
	}

	return result;
}