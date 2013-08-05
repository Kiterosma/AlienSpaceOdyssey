#include "sfmlb2d.h"

b2Vec2 sfmlb2d::SFTOB2Vec2f(sf::Vector2f input)
{
	return b2Vec2(input.x, input.y);
}

sf::Vector2f sfmlb2d::B2TOSFVec2f(b2Vec2 input)
{
	return sf::Vector2f(input.x, input.y);
}

