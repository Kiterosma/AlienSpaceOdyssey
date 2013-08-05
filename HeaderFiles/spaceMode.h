#ifndef SPACEMODE_H
#define SPACEMODE_H

#include "element.h"
#include "application.h"
#include "background.h"
#include "entity.h"
#include "overheadPlayer.h"
#include "asteroid.h"

class Application;

class SpaceMode: public Element
{
public:
	SpaceMode(Application* a);
	virtual ~SpaceMode();
	virtual void initialize(Screen screen);
	virtual void draw();
	virtual void handleEvent(const Event & event);
	virtual void update();

private:
	Application* application;
	Time newFrame;
	Time oldFrame;
	Entity* player;
	list<Entity*> entities;
	b2World* world;

	void updateEntities(float diff);

};

#endif