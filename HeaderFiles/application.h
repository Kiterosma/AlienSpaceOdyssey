#ifndef APPLICATION_H
#define APPLICATION_H


//#include "preLoad.h"
#include "SFML\Audio.hpp"
#include <stack>
#include "Element.h"

using namespace sf;
using namespace std;

class Menu;
class GameObject;

class Application{

public:
	Application();
	~Application();

	bool initialize(Element* elem);
	void run();
	void addToStack(Element* elem, Element::Screen screen);
	void removeTop();
	Vector2f localMouseCoords();

	ControlsConfig controls;

	bool fullscreen;

	RenderWindow window;
	int xRes, yRes; //add initialization to these when a save file is made for this information

	string WorkingDirectory;

	Texture Blank, MainMenu, ControlsMenu, GUIButton1, BackButton, MessageBox, Starfield, UFO, LaserSprite, Reticle, Cursor,
			Asteroid;

	SoundBuffer OUGH;

	Font Rounded;

	Clock clock;

private:
	stack<Element*> elems;
	Element* secondInStack;
	bool transparentElement;

	void update();
	void toggleFullscreen();
	void initializeWindow();
	
};

#endif