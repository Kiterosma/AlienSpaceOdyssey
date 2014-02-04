#ifndef SPACEMODE_H
#define SPACEMODE_H

#include "Background.h"
#include "OverheadPlayer.h"
#include "Asteroid.h"
#include "EntityContactListener.h"
#include "GameMode.h"

class Application;

class SpaceMode: public GameMode
{
public:
	SpaceMode(Application* a);
	virtual ~SpaceMode();
	virtual void initialize(Screen screen);
	virtual void draw();
	virtual void handleEvent(const Event & event);
	virtual void preUpdate();
	virtual void postUpdate();
};

#endif