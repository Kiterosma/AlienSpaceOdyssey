#include "Entity.h"
#include <iostream>

Entity::Entity(Application* a, b2World* w, Texture & t, IntRect rect, Vector2f pos, Vector2f vel):despawn(false),health(20),doDraw(true)
{
	application = a;

	sprite.setTexture(t);
	sprite.setTextureRect(rect);
	sprite.setPosition(pos);

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.linearVelocity.Set(vel.x, vel.y);
	bodyDef.position.Set(pos.x,pos.y);
	body = w->CreateBody(&bodyDef);

}

Entity::~Entity()
{
	if(body && body->GetWorld()) body->GetWorld()->DestroyBody(body);
	cout<<"GOODBYE"<<endl;
}

void Entity::draw()
{
	if(doDraw) application->window.draw(sprite);
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
	float dtr = DEG_TO_RAD;

	sprite.setPosition(getPositionPixels());
	sprite.setRotation(body->GetAngle()/dtr);
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

/*
Angle is in degrees.
*/
void Entity::rotate(float angle)
{
	float dtr = DEG_TO_RAD;
	body->SetTransform(body->GetPosition(), angle*dtr);
}

void Entity::beginContact(void* other)
{

}

void Entity::endContact(void* other)
{

}

void Entity::damage(int amount)
{
	health -= amount; //this function will be more complex in the future
}

Entity::ID Entity::getID()
{
	return Entity::default;
}