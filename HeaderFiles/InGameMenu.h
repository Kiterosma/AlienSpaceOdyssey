#ifndef INGAMEMENU_H
#define INGAMEMENU_H

#include "Menu.h"

class InGameMenu : public Menu
{
	InGameMenu(Application* a);
	virtual bool isTransparent(){return true;}
};

#endif