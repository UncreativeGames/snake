#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP

#include "Snake.hpp"
#include "Maca.hpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class GameController
{
public:
	GameController(Snake* snake, Maca* frutinha, sf::RenderWindow* window);

	void update(const sf::Time& delta_time);

private:
	sf::RenderWindow* window;
	Snake* snake;
	Maca* frutinha;
};

#endif
