#include "PlatformerPlayer.h"

PlatformerPlayer::PlatformerPlayer(Application* a, b2World* w, Vector2f pos):Entity(a, w, a->Mario, IntRect(0,0,100,100/*211,0,12,15*/), pos, Vector2f(0,0))
{
	float ppm = PIXELS_PER_METER;

	sprite.setOrigin(211,15);

	body->SetTransform(b2Vec2(pos.x, pos.y + 7.5/ppm),0);

	b2PolygonShape rect1, rect2;
	rect1.SetAsBox(6/ppm,7.5/ppm);

	rect2.SetAsBox(6/ppm, 2.5/ppm);
	rect2.m_centroid = b2Vec2(0, -2.5/ppm);

	b2FixtureDef fixtureDef1, fixtureDef2;
	fixtureDef1.shape = &rect1;
	fixtureDef1.density = 1.f; //density subject to change
	body->CreateFixture(&fixtureDef1);
	body->SetUserData(this);

	fixtureDef2.isSensor = true;
	fixtureDef2.shape = &rect2;

	b2Fixture* sensor = body->CreateFixture(&fixtureDef2);
	sensor->SetUserData((void*)(-1));
	
}

list<Entity*> PlatformerPlayer::update(float diff)
{
	list<Entity*> result;
	
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Right")))
	{
		accelerateCenter(b2Vec2(.5f, 0.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Move Left")))
	{
		accelerateCenter(b2Vec2(-.5f, 0.f));
	}
	if(Keyboard::isKeyPressed(application->controls.getKey("Jump")) && canJump)
	{
		float impulse = body->GetMass()*3;
		body->ApplyLinearImpulse( b2Vec2(0,impulse), body->GetWorldCenter());
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