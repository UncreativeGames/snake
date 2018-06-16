#include "../include/GameController.hpp"

GameController::GameController(Snake* snake, Maca* frutinha, sf::RenderWindow* window)
{
	this->snake = snake;
	this->frutinha = frutinha;
	this->window = window;
}

void GameController::update(const sf::Time& delta_time)
{
	//while( window->pollEvent(event) )
		//if ( event.type == sf::Event::KeyPressed )
		//{
			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) snake->changeDirection(sf::Vector2f(0,-1));

			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) snake->changeDirection(sf::Vector2f(0,1));

			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) snake->changeDirection(sf::Vector2f(-1,0));

			if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) snake->changeDirection(sf::Vector2f(1,0));
		//}

			

	snake->update(delta_time, *frutinha);
	if ( snake->eat(*frutinha) )
		do
		{
			frutinha->sortPosition();
		} while ( snake->isOverMe(*frutinha) );
}

