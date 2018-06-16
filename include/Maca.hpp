#ifndef MACA_HPP
#define MACA_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdlib>
#include "Config.hpp"
#include "Snake.hpp"

class Maca : public sf::RectangleShape
{
public:
	Maca();
	void sortPosition();
};

#endif
