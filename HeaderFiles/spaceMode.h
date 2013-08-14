#ifndef SPACEMODE_H
#define SPACEMODE_H

#include "background.h"
#include "overheadPlayer.h"
#include "asteroid.h"
#include "entityContactListener.h"

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
	EntityContactListener contactListener;
	float viewZoom;

	void updateEntities(float diff);
	void zoomView(int mouseWheelTicks);

};

#endif