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
	sound.play();

	b2PolygonShape square;
	square.SetAsBox(261/ppm,23/ppm,b2Vec2(0,0),angle);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &square;
	body->CreateFixture(&fixtureDef);
	body->SetBullet(true);
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

void Projectile::beginConact(void* other)
{
	if(typeid(other)==typeid(Entity))
	{
		Entity* entity = static_cast<Entity*>(other);
		entity->damage(1);
		deathTimer = -1.f;
	}
}

void Projectile::endContact(void* other)
{

}