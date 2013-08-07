#ifndef ENTITYCONTACTLISTENER_H
#define ENTITYCONTACTLISTENER_H

#include <Box2D\Box2D.h>

class EntityContactListener: public b2ContactListener
{
public:
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PreSolve(b2Contact* contact);
};

#endif