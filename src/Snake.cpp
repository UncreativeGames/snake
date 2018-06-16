#include "../include/Snake.hpp"
#include <cmath>
#include <iostream>

Snake::Snake(int x, int y)
{
	body = new FilaEstatica<SnakeNode>();
	body->enqueue(new SnakeNode(x,y));
	atual_position = sf::Vector2f(x,y);
	last_direction = sf::Vector2f(0,-1);
	atual_direction = sf::Vector2f(0,-1);
	move_time = speed;
	current_time = sf::seconds(0.f);
}

Snake::~Snake()
{
	delete body;
}

void Snake::changeDirection(const sf::Vector2f& direction)
{
	if ( direction + last_direction == sf::Vector2f(0,0) )
		return;

	atual_direction = direction;
}

void Snake::update(const sf::Time& frameTime, const sf::Shape& fruit)
{
	bool isAccelerated = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
	sf::Time new_move_time = move_time / ((isAccelerated) ? 2.f : 1.f);
	current_time += frameTime;

	if ( current_time < new_move_time )
		return;

	current_time = current_time % new_move_time;
	atual_position += last_direction;
	if ( atual_position.x < 0 ) 			atual_position.x = largura - 1;
	if ( atual_position.x > (largura - 1) ) atual_position.x = 0;
	if ( atual_position.y < 0 ) 			atual_position.y = altura - 1;
	if ( atual_position.y > (altura - 1) )  atual_position.y = 0;

	body->enqueue(new SnakeNode(atual_position.x, atual_position.y));
	if ( !eat(fruit) )
		delete body->dequeue();
	last_direction = atual_direction;
}

bool Snake::selfCannibalism()
{
	bool flag = false;
	sf::Vector2f posicao_in_pixels = atual_position * (float)pixels_per_square_in_grid;
	for ( int i = 0; i < length() - 1; i++ )
	{
		SnakeNode* parte_do_corpo = body->dequeue();
		if ( Mesma_posicao(posicao_in_pixels, parte_do_corpo) )
			flag = true;
		body->enqueue(parte_do_corpo);
	}
	body->enqueue(body->dequeue());

	return flag;
}

bool Snake::eat(const sf::Shape& fruit)
{
	if ( atual_position * (float)pixels_per_square_in_grid == fruit.getPosition() )
		return true;
}

bool Snake::isOverMe(const sf::Shape& fruit)
{
	bool flag = false;
	for ( int i = 0; i < length(); i++ )
	{
		SnakeNode* parte_do_corpo = body->dequeue();
		if ( Mesma_posicao(fruit.getPosition(), parte_do_corpo) )
			flag = true;
		body->enqueue(parte_do_corpo);
	}
	return flag;
}

int Snake::length()
{
	return body->length();
}

void Snake::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for ( int i = 0; i < body->length(); i++ )
	{
		target.draw(*body->front());
		body->enqueue(body->dequeue());
	}
}
