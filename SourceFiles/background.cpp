#include "Background.h"

Background::Background(Application* a, Texture & t, View & v, bool scale):view(v)
{
	application = a;
	sprite.setTexture(t);
	if(scale) scaleToView();
}

void Background::draw()
{
	application->window.draw(sprite);
}

void Background::setTexture(Texture & t)
{
	sprite.setTexture(t);
}

void Background::scaleToView()
{
	float spriteWidth = sprite.getGlobalBounds().width;
	float spriteHeight = sprite.getGlobalBounds().height;
	float viewWidth = view.getSize().x;
	float viewHeight = view.getSize().y;
	sprite.scale(viewWidth/spriteWidth, viewHeight/spriteHeight);
}