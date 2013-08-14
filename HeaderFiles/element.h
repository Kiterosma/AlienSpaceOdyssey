#ifndef ELEMENT_H
#define ELEMENT_H

//#include "preLoad.h"
#include "GameObject.h"

using namespace sf;
using namespace std;

/*
Resposible for updating game entities.
*/
class Element{

public:
	enum Screen{MainMenu, Controls, InGame};

	void clear()
	{
		list<GameObject*>::iterator it = objects.begin();
		while(it!=objects.end())
		{
			delete *it;
			*it = NULL;
			it++;
		}
	}

	virtual ~Element(){clear();}
	virtual void initialize(Screen screen)=0;
	virtual void draw()=0;
	virtual void handleEvent(const Event & event)=0;
	virtual void update()=0;

protected:
	list<GameObject*> objects;
	View view;
	Sprite cursor;

};

#endif