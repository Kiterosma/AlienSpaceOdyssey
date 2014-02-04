#ifndef ELEMENT_H
#define ELEMENT_H

//#include "preLoad.h"
#include "GameObject.h"

using namespace sf;
using namespace std;

class Application;

/*
Resposible for updating game entities.
*/
class Element{

public:
	enum Screen{MainMenu, Controls, InGame};

	Element(Application* a);
	virtual ~Element();
	virtual void initialize(Screen screen)=0;
	virtual void draw();
	virtual void handleEvent(const Event & event)=0;
	virtual void update()=0;
	virtual bool isTransparent();

protected:
	Application* application;
	list<GameObject*> objects;
	View view;
	Sprite cursor;

	void clear();
};

#endif