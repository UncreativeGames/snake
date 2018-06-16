#ifndef SNAKENODE_HPP
#define SNAKENODE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstdlib>
#include "Config.hpp"

class SnakeNode : public sf::RectangleShape
{
public:
	SnakeNode(int x, int y);
};

#endif
