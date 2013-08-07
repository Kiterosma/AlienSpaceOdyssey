#include "asteroid.h"

Asteroid::Asteroid(Application* a, b2World* w, Vector2f pos, Vector2f vel):Entity(a, w, a->Asteroid,IntRect(0,0,238,174), pos, vel)
{
	float ppm = PIXELS_PER_METER;

	sprite.setOrigin(119.f,87.f);

	/*
	The order in which this was done is strange because the points
	must be set in CCW order, and I was too lazy to switch all of the
	lines around, but not lazy enough to not make a long-winded comment.
	*/
	b2Vec2 vertices[8];
	vertices[7].Set(-101.f/ppm, -70.f/ppm);
	vertices[6].Set(-113.f/ppm, 28.f/ppm);
	vertices[5].Set(-37.f/ppm, 73.f/ppm);
	vertices[4].Set(65.f/ppm, 79.f/ppm);
	vertices[3].Set(110.f/ppm, 48.f/ppm);
	vertices[2].Set(81.f/ppm, -9.f/ppm);
	vertices[1].Set(55.f/ppm, -37.f/ppm);
	vertices[0].Set(-56.f/ppm, -84.f/ppm);

	b2PolygonShape polygonShape;
	polygonShape.Set(vertices, 8);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &polygonShape;
	fixtureDef.density = 1.f; //density subject to change
	body->CreateFixture(&fixtureDef);

	body->SetAngularVelocity(.349f);
}

list<Entity*> Asteroid::update(float diff)
{
	list<Entity*> result = Entity::update(diff);

	return result;
}