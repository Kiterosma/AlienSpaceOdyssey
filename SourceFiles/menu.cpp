#include "menu.h"

using namespace std;

Menu::Menu(Application* a):application(a),highlighted(NULL),controls(NULL),controlSelection(false)
{

}

Menu::~Menu()
{
	if(controls!=NULL)
	{
		delete controls;
		controls=NULL;
	}
}

void Menu::initialize(Screen screen)
{
	clear();
	highlighted=NULL;
	if(controls!=NULL)
	{
		delete controls;
		controls=NULL;
	}

	switch(screen)
	{
	case MainMenu: buildMainMenu();
		break;
	case Controls: buildControlsMenu();
		break;
	}

	cursor.setTexture(application->Cursor);
	cursor.setOrigin(0.f,0.f);
	cursor.scale(.5f,.5f);
}

void Menu::draw()
{
	application->window.setView(view);

	list<GameObject*>::iterator it = objects.begin();
	while(it!=objects.end())
	{
		(*it)->draw();
		it++;
	}
	application->window.draw(cursor);
}

void Menu::handleEvent(const Event & event)
{
	switch(event.type)
	{
	case Event::MouseMoved: hover();
		break;
	case Event::MouseButtonPressed:
		if(controlSelection)
		{
			string function = currentButton->getString();
			controls->setMouseButton(function, event.mouseButton.button);
			objects.pop_back();
			
			refreshControlsMenu();
			currentButton = NULL;
			controlSelection = false;
		}
		else if(Mouse::isButtonPressed(Mouse::Left)) press(true);
		break;
	case Event::MouseButtonReleased: if(!Mouse::isButtonPressed(Mouse::Left)) press(false);
		break;
	case Event::KeyPressed:
		if(controlSelection)
		{
			string function = currentButton->getString();
			controls->setKey(function, event.key.code);
			objects.pop_back();

			refreshControlsMenu();
			currentButton = NULL;
			controlSelection = false;
		}
		break;
	}
}

void Menu::update()
{
	cursor.setPosition(application->localMouseCoords());
}

void Menu::buildMainMenu()
{
	font = application->Rounded;

	view.setViewport(FloatRect(0,0,1,1));

	objects.push_back(new Background(application, application->MainMenu, view, true));
	objects.push_back(new GUIButton(application, application->GUIButton1, Vector2f(345.f, 350.f), Text("New Game",font,34), GameObject::NewGame, NULL));
	objects.push_back(new GUIButton(application, application->GUIButton1, Vector2f(345.f, 500.f), Text("Options",font,34), GameObject::Controls, NULL));
}

void Menu::buildControlsMenu()
{
	if(controls==NULL)
		controls = new ControlsConfig(application->controls);

	font = application->Rounded;

	view.setViewport(FloatRect(0,0,1,1));

	objects.push_back(new Background(application, application->ControlsMenu, view, true));

	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Up") , Vector2f(500.f, 10.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 10.f), Text("Move Up",font,30), GameObject::ControlSet, (TextBox*)objects.back()));

	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Down"), Vector2f(500.f, 70.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 70.f), Text("Move Down",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Left"), Vector2f(500.f, 130.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 130.f), Text("Move Left",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Right"), Vector2f(500.f, 190.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 190.f), Text("Move Right",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Shoot"), Vector2f(500.f, 250.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 250.f), Text("Shoot",font,30), GameObject::ControlSet, (TextBox*)objects.back()));

	objects.push_back(new GUIButton(application, application->BackButton, Vector2f(30.f, 900.f), Text(), GameObject::Back, NULL));
	objects.push_back(new GUIButton(application, application->MessageBox, Vector2f(750.f, 900.f), Text("Save Changes",font,30), GameObject::SaveChanges, NULL));

}

void Menu::hover()
{
	Vector2f vector = application->localMouseCoords();

	list<GameObject*>::iterator it = objects.begin();
	while(it!=objects.end())
	{
		if((*it)->hover(vector))
		{
			highlighted = *it;
			break;
		}
		else
			highlighted = NULL;
		it++;
	}
}

void Menu::press(bool down)
{
	list<GameObject*>::iterator it = objects.begin();
	while(it!=objects.end())
	{
		if(down) (*it)->pressDown();
		else
		{
			processFunc((*it)->pressUp());
		}
		it++;
	}
}

void Menu::processFunc(GameObject::Function func)
{
	switch(func)
	{
	case GameObject::Back:
		application->removeTop();
		break;
	case GameObject::Home:
		break;
	case GameObject::Controls:
		application->addToStack(new Menu(application), Controls);
		break;
	case GameObject::NewGame:
		application->addToStack(new SpaceMode(application), InGame);
		break;
	case GameObject::ControlSet:
		objects.push_back(new TextBox(application, application->MessageBox, "Press any key/button to set its function.", Vector2f(300.f, 250.f), GameObject::MessageBox));
		controlSelection = true;
		currentButton = (GUIButton*)highlighted; //not sure if this is the best way of getting the current button
		break;
	case GameObject::SaveChanges:
		application->controls = *controls;
		controls->writeToFile(application->WorkingDirectory+"Config\\controls.dat");
		break;
	case GameObject::None: 
		break;
	}
}

string Menu::getButtonString(std::string function)
{
	switch(controls->getMode())
	{
	case ControlsConfig::KeyboardMouse:
		{
		std::string mouse = ControlsConfig::mouseToString(controls->getMouseButton(function));
		std::string keyboard = ControlsConfig::keyToString(controls->getKey(function));
		return (keyboard!="Unbound")? keyboard:mouse;
		}
	case ControlsConfig::Joystick:
		{
		std::string axis = ControlsConfig::axisToString(controls->getAxis(function));
		std::string button = ControlsConfig::buttonToString(controls->getMouseButton(function));
		return (axis!="Unbound")? axis:button;
		}
	}
}

void Menu::refreshControlsMenu()
{
	while(objects.size()>1)
		objects.pop_back();

	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Up") , Vector2f(500.f, 10.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 10.f), Text("Move Up",font,30), GameObject::ControlSet, (TextBox*)objects.back()));

	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Down"), Vector2f(500.f, 70.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 70.f), Text("Move Down",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Left"), Vector2f(500.f, 130.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 130.f), Text("Move Left",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Move Right"), Vector2f(500.f, 190.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 190.f), Text("Move Right",font,30), GameObject::ControlSet, (TextBox*)objects.back()));
	
	objects.push_back(new TextBox(application, application->Blank, getButtonString("Shoot"), Vector2f(500.f, 250.f), GameObject::None));
	objects.push_back(new GUIButton(application, application->Blank, Vector2f(10.f, 250.f), Text("Shoot",font,30), GameObject::ControlSet, (TextBox*)objects.back()));

	objects.push_back(new GUIButton(application, application->BackButton, Vector2f(30.f, 900.f), Text(), GameObject::Back, NULL));
	objects.push_back(new GUIButton(application, application->MessageBox, Vector2f(750.f, 900.f), Text("Save Changes",font,30), GameObject::SaveChanges, NULL));
}