#ifndef MENU_H
#define MENU_H

#include "guiButton.h"
#include "background.h"
#include "spaceMode.h"

class SpaceMode;
class Application;

class Menu: public Element{

public:
	Menu(Application* a);
	virtual ~Menu();
	virtual void draw();
	virtual void handleEvent(const Event & event);
	virtual void initialize(Screen screen);
	virtual void update();

private:
	void buildMainMenu();
	void buildControlsMenu();
	void hover();
	void press(bool down);
	void processFunc(GameObject::Function func);
	string getButtonString(std::string function);
	void refreshControlsMenu();

	Application* application;
	GameObject* highlighted;
	ControlsConfig* controls;
	GUIButton* currentButton;
	Font font;
	bool controlSelection;
	
};

#endif