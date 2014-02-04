#include "Application.h"

Application::Application():controls(this, ControlsConfig::KeyboardMouse)
{
	fullscreen = false;
	transparentElement = false;
	secondInStack = NULL;
	initializeWindow();
}

Application::~Application()
{
	while(!elems.empty())
	{
	//delete elems.top(); this line seems to be redundant
		elems.pop();
	}
}

bool Application::initialize(Element* elem)
{
	bool result = true;

	elems.push(elem);
	
	//load working directory and load necessary files
	WorkingDirectory = "C:\\Users\\Acer\\Documents\\Visual Studio 2012\\Projects\\AlienSpaceOdyssey\\"; //change to read from config file (can be different for every user)
	
	if(!controls.fileExists(WorkingDirectory+"Config\\controls.dat"))
	{
		controls.revertToDefault();
		controls.writeToFile(WorkingDirectory+"Config\\controls.dat");
	}
	else controls.readFromFile(WorkingDirectory+"Config\\controls.dat");

	//Load textures
	result = result && Blank.loadFromFile(WorkingDirectory+"Textures\\Blank.png");
	result = result && MainMenu.loadFromFile(WorkingDirectory+"Textures\\MainMenu.png");
	result = result && ControlsMenu.loadFromFile(WorkingDirectory+"Textures\\OptionsMenu.png");
	result = result && GUIButton1.loadFromFile(WorkingDirectory+"Textures\\GUIButton1.png");
	result = result && BackButton.loadFromFile(WorkingDirectory+"Textures\\BackButton.png");
	result = result && MessageBox.loadFromFile(WorkingDirectory+"Textures\\MessageBox.png");
	result = result && Starfield.loadFromFile(WorkingDirectory+"Textures\\starfield.png");
	result = result && UFO.loadFromFile(WorkingDirectory+"Textures\\UFO.png");
	result = result && LaserSprite.loadFromFile(WorkingDirectory+"Textures\\LaserSprite.png");
	result = result && Reticle.loadFromFile(WorkingDirectory+"Textures\\Reticle.png");
	result = result && Cursor.loadFromFile(WorkingDirectory+"Textures\\Cursor.png");
	result = result && Asteroid.loadFromFile(WorkingDirectory+"Textures\\Asteroid.png");

	//Load sounds
	result = result && OUGH.loadFromFile(WorkingDirectory+"Sounds\\OUGH.ogg");

	//Load fonts
	result = result && Rounded.loadFromFile(WorkingDirectory+"Fonts\\Rounded.ttf");

	elems.top()->initialize(Element::MainMenu);

	return result;
}

void Application::run()
{
	while(window.isOpen())
	{
        window.clear();

		update();

		if(window.isOpen())
		{
			if(elems.top()!=NULL)
			{
				if(transparentElement)
					secondInStack->draw();
				elems.top()->draw();
			}

		  window.display();
		}

    }
}

void Application::update()
{
	Event event;
	while (window.pollEvent(event) && window.isOpen())
	{
		switch(event.type)
		{
		case Event::Closed:window.close();
			break;
		case Event::KeyPressed:
			if(Keyboard::isKeyPressed(Keyboard::LAlt) && Keyboard::isKeyPressed(Keyboard::Return))
			{
				toggleFullscreen();
			}
			else
				elems.top()->handleEvent(event);
			break;
		default: elems.top()->handleEvent(event);
		}
	}

	if(window.isOpen())
	elems.top()->update();
}

void Application::toggleFullscreen()
{
	if(fullscreen)
	{
		window.close();
		fullscreen = false;
		initializeWindow();
	}
	else
	{
		window.close();
		fullscreen = true;
		initializeWindow();
	}
}

void Application::addToStack(Element* elem, Element::Screen screen)
{
	elem->initialize(screen);
	if(elem->isTransparent())
	{
		secondInStack = elems.top();
		transparentElement = true;
	}
	elems.push(elem);
}

void Application::removeTop()
{
	if(elems.top()->isTransparent())
	{
		transparentElement = false;
		secondInStack = NULL;
	}
	elems.pop();
}

Vector2f Application::localMouseCoords()
{
	Vector2i windowBorder(8,30);
	Vector2i zero(0,0);
	Vector2i vector1 = Mouse::getPosition() - window.getPosition() - ((fullscreen)? zero:windowBorder);
	return window.mapPixelToCoords(vector1);
}

void Application::initializeWindow()
{
	if(!fullscreen)
		window.create(VideoMode(800, 600), "Alien Space Odyssey", Style::Titlebar|Style::Close);
	else
		window.create(VideoMode(1366,768), "Alien Space Odyssey", Style::Fullscreen);

	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);
	window.setMouseCursorVisible(false);
}