#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "application.h"

class Background: public GameObject{

public:
	Background(Application* a, Texture & t, View & v, bool scale);
	virtual void draw();
	virtual void setTexture(Texture & t);

private:
	Sprite sprite;
	View view;

	void scaleToView();

};

#endif
