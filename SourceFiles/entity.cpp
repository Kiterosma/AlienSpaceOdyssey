#include "entity.h"

Entity::Entity(Application* a, b2World* w, Texture & t, IntRect rect, Vector2f pos, Vector2f vel):despawn(false)
{
	application = a;

	sprite.setTexture(t);
	sprite.setTextureRect(rect);
	sprite.setPosition(pos);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.allowSleep = true;
	bodyDef.linearVelocity.Set(vel.x, vel.y);
	bodyDef.position.Set(pos.x,pos.y);
	body = w->CreateBody(&bodyDef);
}

void Entity::draw()
{
	application->window.draw(sprite);
}

void Entity::setTexture(Texture & t)
{
	sprite.setTexture(t);
}

void Entity::setRect(IntRect rect)
{
	sprite.setTextureRect(rect);
}

/*
Returns velocity in m/s, with respect to the Box2D world.
*/
b2Vec2 Entity::getVelocity()
{
	return body->GetLinearVelocity();
}

void Entity::setVelocity(b2Vec2 vel)
{
	body->SetLinearVelocity(vel);
}

/*
Returns position in meters, with respect to the Box2D world.
*/
b2Vec2 Entity::getPositionMeters()
{
	return body->GetPosition();
}

/*
Returns position in pixels.
*/
Vector2f Entity::getPositionPixels()
{
	return sfmlb2d::B2TOSFVec2f(body->GetPosition())*PIXELS_PER_METER;
}

list<Entity*> Entity::update(float diff)
{
	sprite.setPosition(getPositionPixels());
	return list<Entity*>();
}

void Entity::accelerateCenter(b2Vec2 force)
{
	body->ApplyForceToCenter(force);
}

void Entity::idle()
{
	//empty by default
}