#ifndef SFMLB2D_H
#define SFMLB2D_H

#include "preLoad.h"

namespace sfmlb2d
{
	b2Vec2 SFTOB2Vec2f(sf::Vector2f input);
	sf::Vector2f B2TOSFVec2f(b2Vec2 input);
};

#endif