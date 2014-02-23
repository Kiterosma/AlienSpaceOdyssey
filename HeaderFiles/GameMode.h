#ifndef GAMEMODE_H
#define GAMEMODE_H

#include "Element.h"
#include "Entity.h"
#include "EntityContactListener.h"

/*
*Abstract class. Outlines all Elements which contain a physics world and game Entities.
*/
class GameMode: public Element
{
public:
	GameMode(Application* a, b2Vec2 gravity);
	virtual ~GameMode();
	virtual void initialize(Screen screen)=0;
	virtual void handleEvent(const Event & event)=0;
	virtual void preUpdate()=0;
	virtual void postUpdate()=0;

protected:
	Time newFrame;
	Time oldFrame;
	Entity* player;
	list<Entity*> entities;
	b2World* world;
	EntityContactListener contactListener;
	float viewZoom;
	bool paused;

	virtual void updateEntities(float diff);
	virtual void zoomView(int mouseWheelTicks);
	virtual void pause();

private:
	virtual void update();
};

#endif