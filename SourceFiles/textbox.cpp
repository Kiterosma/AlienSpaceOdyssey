#include "Textbox.h"

TextBox::TextBox(Application* a, Texture & t, string s, Vector2f position, Function func):application(a), function(func)
{
	sprite.setTexture(t);

	switch(func)
	{
	case None:
		lines.push_back(Text(s, application->Rounded, 30));
		lines[0].setPosition(position);
		lines[0].setColor(Color::Black);
		sprite.setColor(Color(0,0,0,0));
		break;
	case MessageBox:
		sprite.setPosition(position);
		allocateLines(s, application->Rounded, Color::Black, 30);
		break;
	}
}

void TextBox::draw()
{
	application->window.draw(sprite);
	
	for(int i=0; i<lines.size(); i++)
		application->window.draw(lines[i]);
}

void TextBox::setTexture(Texture & t)
{
	sprite.setTexture(t);
}

void TextBox::allocateLines(string & s, Font & font, Color color, int size)
{
	FloatRect rect = sprite.getGlobalBounds();

	string curr = "";
	Text t(curr, font, size);
	t.setColor(color);
	size_t pos = 0;
	bool cutoff = false;
	int line = 0;

	while(pos < s.length())
	{
		size_t next = s.find_first_of(" ",pos);
		if(next > s.length()) next = s.length();

		if(cutoff)
		{
			string nextString = s.substr(pos, next-pos+1);
			curr = (nextString[0] == ' ')? nextString.substr(1):nextString;
			cutoff = false;
			pos = next+1;
		}
		else
		{
			string nextString = curr + s.substr(pos, next-pos+1);
			t.setString(nextString);
			FloatRect textRect = t.getGlobalBounds();
			if(textRect.width > rect.width)
			{
				t.setString(curr);
				lines.push_back(Text(t));
				line++;
				cutoff = true;
			}
			else
			{
				curr = nextString;
				pos = next+1;
			}
		}
	}

	t.setString(curr);
	lines.push_back(Text(t));

	float height = line*((float)size+10.f) +size;
	float yOffset = (rect.height-height)/2;

	for(int i=0; i<lines.size(); i++)
	{
		FloatRect textRect = lines[i].getGlobalBounds();
		lines[i].setPosition(rect.left + (rect.width-textRect.width)/2, rect.top + yOffset + 40.f*i);
	}
}