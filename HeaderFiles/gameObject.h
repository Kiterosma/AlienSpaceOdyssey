#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "ControlsConfig.h"
using namespace sf;

class Application;

class GameObject{

public:
	enum Function{None, Back, Home, NewGame, Controls, ControlSet, MessageBox, SaveChanges};

	virtual ~GameObject(){}
	virtual void draw()=0;
	virtual void setTexture(Texture & t)=0;
	virtual bool hover(Vector2f vector){return false;}
	virtual void pressDown(){}
	virtual Function pressUp(){return None;}

protected:

	Application* application;

private:
	

};

#endif