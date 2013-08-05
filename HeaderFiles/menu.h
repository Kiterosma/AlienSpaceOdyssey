#ifndef MENU_H
#define MENU_H

#include "application.h"
#include "element.h"
#include "guiButton.h"
#include "background.h"
#include "textbox.h"
#include "controlsConfig.h"
#include "spaceMode.h"

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