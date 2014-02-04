#include "Element.h"
#include "Application.h"

Element::Element(Application* a)
{

}

Element::~Element()
{
	clear();
}

void Element::clear()
{
	list<GameObject*>::iterator it = objects.begin();
	while(it!=objects.end())
	{
		delete *it;
		*it = NULL;
		it++;
	}
}

bool Element::isTransparent()
{
	return false;
}

void Element::draw()
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