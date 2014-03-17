#include "PlatformerPlayer.h"

PlatformerPlayer::PlatformerPlayer(Application* a, b2World* w, Vector2f pos):Entity(a, w, a->Mario, IntRect(211,0,12,15), pos, Vector2f(0,0))
{
	float ppm = PIXELS_PER_METER;

	sprite.setOrigin(0,15);

	b2PolygonShape rect1, rect2;
	rect1.SetAsBox(6/ppm,7.5f/ppm, b2Vec2(6/ppm, 7.5f/ppm), 0);

	rect2.SetAsBox(6/ppm, 2.5f/ppm, b2Vec2(6/ppm, 14.f/ppm), 0);

	b2FixtureDef fixtureDef1, fixtureDef2;
	fixtureDef1.shape = &rect1;
	fixtureDef1.density = 1.5f;
	body->CreateFixture(&fixtureDef1);
	body->SetUserData(this);

	fixtureDef2.density = 1;
	fixtureDef2.isSensor = true;
	fixtureDef2.shape = &rect2;
	fixtureDef2.userData = (void*)(-1);
	body->CreateFixture(&fixtureDef2);
}

list<Entity*> PlatformerPlayer::update(float diff)
{
	list<Entity*> result;

	Entity::update(diff);
	
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Right")))
	{
		accelerateCenter(b2Vec2(.1f, 0.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Left")))
	{
		accelerateCenter(b2Vec2(-.1f, 0.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Jump")))
	{
		jump(3, .5f);
	}

	return result;
}

void PlatformerPlayer::idle()
{

}

Entity::ID PlatformerPlayer::getID()
{
	return platformerplayer;
}

void PlatformerPlayer::beginContact(void* other)
{

}

void PlatformerPlayer::endContact(void* other)
{

}