#ifndef GUIBUTTON_H
#define GUIBUTTON_H

#include "textbox.h"

class GUIButton: public GameObject{

public:
	GUIButton(Application* a, Texture & t, Vector2f pos, Text & txt, Function func, TextBox* txtBox);
	virtual ~GUIButton();
	virtual void draw();
	virtual void setTexture(Texture & t);
	virtual bool hover(Vector2f vector);
	virtual void pressDown();
	virtual Function pressUp();
	virtual string getString();

	TextBox* textBox;

private:
	Sprite sprite;
	FloatRect rect;
	Text text;
	FloatRect textRect;
	Function function;
	bool highlighted;
	bool pressed;

	void scaleUp();
	void scaleDown();
	void highlight(bool on);
};

#endif
