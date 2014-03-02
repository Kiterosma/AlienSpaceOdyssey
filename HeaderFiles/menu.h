#ifndef MENU_H
#define MENU_H

#include "GuiButton.h"
#include "Background.h"
#include "SpaceMode.h"
#include "PlatformerMode.h"

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

	GameObject* highlighted;
	ControlsConfig* controls;
	GUIButton* currentButton;
	Font font;
	bool controlSelection;
	
};

#endif