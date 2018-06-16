#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "FilaEstatica.hpp"
#include "Config.hpp"
#include "SnakeNode.hpp"

class Snake : public sf::Drawable
{
public:
	Snake(int x, int y);
	~Snake();

	void changeDirection(const sf::Vector2f& direction = sf::Vector2f(0,0));
	void update(const sf::Time& frameTime, const sf::Shape& fruit);
	bool selfCannibalism();
	bool eat(const sf::Shape& fruit);
	bool isOverMe(const sf::Shape& fruit);
	int  length();

private:
	sf::Vector2f  atual_position;
	sf::Vector2f  atual_direction;
	sf::Vector2f  last_direction;
	FilaEstatica<SnakeNode>* body;
	sf::Time      move_time;
	sf::Time      current_time;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
