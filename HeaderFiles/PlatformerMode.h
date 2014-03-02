#ifndef PLATFORMERMODE_H
#define PLATFORMERMODE_H

#include "GameMode.h"
#include "Background.h"
#include "PlatformerPlayer.h"
#include "OverheadPlayer.h"

class PlatformerMode : public GameMode
{
public:
	PlatformerMode(Application* a);
	virtual ~PlatformerMode();
	virtual void initialize(Screen screen);
	virtual void handleEvent(const Event & event);
	virtual void preUpdate();
	virtual void postUpdate();
};

#endif