#include "EntityContactListener.h"

void EntityContactListener::BeginContact(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	Entity* entityA = static_cast<Entity*>(dataA);
	Entity* entityB = static_cast<Entity*>(dataB);

	if(entityA)
	{
		entityA->beginContact(dataB);
	}

	if(entityB)
	{
		entityB->beginContact(dataA);
	}

}

void EntityContactListener::EndContact(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	Entity* entityA = static_cast<Entity*>(dataA);
	Entity* entityB = static_cast<Entity*>(dataB);

	if(entityA)
	{
		entityA->endContact(dataB);
	}

	if(entityB)
	{
		entityB->endContact(dataA);
	}
}

void EntityContactListener::PreSolve(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

}