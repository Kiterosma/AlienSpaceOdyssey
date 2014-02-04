#include "GuiButton.h"

static const float scaleUpFactor = 1.25f;
static const float scaleDownFactor = 0.8f;

GUIButton::GUIButton(Application* a, Texture & t, Vector2f pos, Text & txt, Function func, TextBox* txtBox):highlighted(false),text(txt),pressed(false),function(func),textBox(txtBox)
{
	application = a;

	Vector2f initScale;
	switch(func)
	{
	case NewGame:
		initScale.x = .5f;
		initScale.y = .5f;
		break;
	case Controls:
		initScale.x = .5f;
		initScale.y = .5f;
		break;
	case Back:
		initScale.x = .5f;
		initScale.y = .5f;
		break;
	case ControlSet:
		initScale.x = 400.f;
		initScale.y = 40.f;
		break;
	case SaveChanges:
		initScale.x = .6f;
		initScale.y = .33f;
		break;
	}

	if(func==ControlSet) highlight(false);

	sprite.setTexture(t);
	sprite.setPosition(pos);
	sprite.setScale(initScale);
	rect = sprite.getGlobalBounds();

	text.setColor(Color::Black);
	textRect = txt.getGlobalBounds();
	float textLeft = (rect.width - textRect.width)/2 + rect.left;
	float textTop = (rect.height - textRect.height)/2 + rect.top;
	text.setPosition(textLeft, textTop);
	textRect = txt.getGlobalBounds();
}

GUIButton::~GUIButton()
{

}

void GUIButton::draw()
{
	application->window.draw(sprite);
	application->window.draw(text);
}

void GUIButton::setTexture(Texture & t)
{
	sprite.setTexture(t);
}

bool GUIButton::hover(Vector2f vector)
{
	bool result = rect.contains(vector);

	if(result && !highlighted)
	{
		scaleUp();

		if(function==ControlSet)
			highlight(true);

		highlighted = true;
	}
	else if(!result && highlighted)
	{
		scaleDown();

		if(function==ControlSet)
			highlight(false);

		highlighted = false;

		pressUp();
	}

	return result;
}

void GUIButton::pressDown()
{
	if(highlighted)
	{
		text.setColor(Color::White);
		pressed = true;
	}
}

GameObject::Function GUIButton::pressUp()
{
	if(pressed)
	{
		text.setColor(Color::Black);
		pressed = false;
		return function;
	}
	return None;
}

void GUIButton::scaleUp()
{
	sprite.scale(scaleUpFactor, scaleUpFactor);
	text.scale(scaleUpFactor, scaleUpFactor);

	float xOffset = (rect.width - rect.width * scaleUpFactor)/2;
	float yOffset = (rect.height - rect.height * scaleUpFactor)/2;

	Vector2f offset(xOffset,yOffset);
	sprite.move(offset);

	offset.x = (textRect.width - textRect.width * scaleUpFactor)/2;
	offset.y = (textRect.height - textRect.height * scaleUpFactor)/2;

	text.move(offset);
}

void GUIButton::scaleDown()
{
	sprite.scale(scaleDownFactor,scaleDownFactor);
	text.scale(scaleDownFactor,scaleDownFactor);

	float xOffset = (rect.width - rect.width * scaleUpFactor)/2;
	float yOffset = (rect.height - rect.height * scaleUpFactor)/2;

	Vector2f offset(-xOffset,-yOffset);
	sprite.move(offset);

	offset.x = -(textRect.width - textRect.width * scaleUpFactor)/2;
	offset.y = -(textRect.height - textRect.height * scaleUpFactor)/2;

	text.move(offset);
}

void GUIButton::highlight(bool on)
{
	if(!on)
		sprite.setColor(Color(0,0,0,0));
	else
		sprite.setColor(Color(255,255,255,100));
}

string GUIButton::getString()
{
	return text.getString();
}