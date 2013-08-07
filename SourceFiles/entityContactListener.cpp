#include "entityContactListener.h"
#include <typeinfo>
#include "entity.h"

class Projectile;
class OverheadPlayer;

void EntityContactListener::BeginContact(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	Entity* entityA = static_cast<Entity*>(dataA);
	Entity* entityB = static_cast<Entity*>(dataB);

	if(entityA)
		entityA->beginContact(dataB);

	if(entityB)
		entityB->beginContact(dataA);

}

void EntityContactListener::EndContact(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	Entity* entityA = static_cast<Entity*>(dataA);
	Entity* entityB = static_cast<Entity*>(dataB);

	if(entityA)
		entityA->endContact(dataB);

	if(entityB)
		entityB->endContact(dataA);
}

void EntityContactListener::PreSolve(b2Contact* contact)
{
	void* dataA = contact->GetFixtureA()->GetBody()->GetUserData();
	void* dataB = contact->GetFixtureB()->GetBody()->GetUserData();

	if( (typeid(dataA)==typeid(Projectile)&&typeid(dataB)==typeid(OverheadPlayer)) || (typeid(dataA)==typeid(OverheadPlayer)&&typeid(dataB)==typeid(Projectile)))
	{
		contact->SetEnabled(false);
	}
}