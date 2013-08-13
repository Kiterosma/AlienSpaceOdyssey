#include "projectile.h"

/*
Angle for contructor is in radians
*/
Projectile::Projectile(Application* a, b2World* w, Vector2f pos, Vector2f vel, float angle, Type type):sound(a->OUGH),speed(20.f),Entity(a, w, a->LaserSprite, IntRect(0,0,290,74), pos, vel + Vector2f(20*std::cosf(angle),20*std::sinf(angle)))
{
	float ppm = PIXELS_PER_METER;

	deathTimer = 5.f;

	sprite.setOrigin(0,37.f);
	sprite.scale(.1f,.1f);
	rotate((angle/(2*3.1416f))*360);
	//sound.play(); the sound is getting too annoying, uncomment this when we get a better sound effect.

	b2PolygonShape square;
	square.SetAsBox(26.1f/ppm,2.3f/ppm,b2Vec2(0,0),angle);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &square;
	fixtureDef.isSensor = true;
	body->CreateFixture(&fixtureDef);
	body->SetBullet(true);
	body->SetUserData(this);
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

void Projectile::beginContact(void* other)
{

	Entity* entity = static_cast<Entity*>(other);

	if(entity)
	{
		entity->damage(1);
	}

	deathTimer = -1.f;
}

void Projectile::endContact(void* other)
{

}

Entity::ID Projectile::getID()
{
	return Entity::projectile;
}