#include "Background.h"

Background::Background(Application* a, Texture & t, View & v):view(v)
{
	application = a;
	sprite.setTexture(t);
	sprite.setPosition(0,0);
}

void Background::draw()
{
	application->window.draw(sprite);
}

void Background::setTexture(Texture & t)
{
	sprite.setTexture(t);
}

void Background::scaleToView(float height)
{
	
}