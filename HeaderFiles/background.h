#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "Application.h"

class Background: public GameObject{

public:
	Background(Application* a, Texture & t, View & v);
	virtual void draw();
	virtual void setTexture(Texture & t);

private:
	Sprite sprite;
	View view;

	void scaleToView(float height);

};

#endif
