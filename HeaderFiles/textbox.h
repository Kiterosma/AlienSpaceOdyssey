#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "gameObject.h"
#include "application.h"

class TextBox: public GameObject
{
public:
	vector<Text> lines;

	TextBox(Application* a, Texture & t, string s, Vector2f position, Function func);
	virtual void draw();
	virtual void setTexture(Texture & t);

private:
	//in the future, there could be a sprite object here for a background
	Sprite sprite;
	Application* application;
	Function function;

	void allocateLines(string & s, Font & font, Color color, int size);
};

#endif