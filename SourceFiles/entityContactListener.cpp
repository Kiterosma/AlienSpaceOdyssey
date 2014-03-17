#include "EntityContactListener.h"
#include <iostream>

void EntityContactListener::BeginContact(b2Contact* contact)
{
	void* bodyDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	void* fixtureDataA = contact->GetFixtureA()->GetUserData();
	void* fixtureDataB = contact->GetFixtureB()->GetUserData();

	Entity* entityA = static_cast<Entity*>(bodyDataA);
	Entity* entityB = static_cast<Entity*>(bodyDataB);

	if(entityA)
	{
		if((int)fixtureDataA == -1)
		{
			entityA->contactGround();
		}
		else
			entityA->beginContact(bodyDataB);
	}

	if(entityB)
	{
		if((int)fixtureDataB == -1)
		{
			entityB->contactGround();
		}
		else
			entityB->beginContact(bodyDataA);
	}

}

void EntityContactListener::EndContact(b2Contact* contact)
{
	void* bodyDataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyDataB = contact->GetFixtureB()->GetBody()->GetUserData();

	void* fixtureDataA = contact->GetFixtureA()->GetUserData();
	void* fixtureDataB = contact->GetFixtureB()->GetUserData();

	Entity* entityA = static_cast<Entity*>(bodyDataA);
	Entity* entityB = static_cast<Entity*>(bodyDataB);

	if(entityA)
	{
		if((int)fixtureDataA == -1)
			entityA->leaveGround();
		else
			entityA->endContact(bodyDataB);
	}

	if(entityB)
	{
		if((int)fixtureDataB == -1)
			entityB->leaveGround();
		else
			entityB->endContact(bodyDataA);
	}
}

void EntityContactListener::PreSolve(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

}