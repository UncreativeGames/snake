#include "../include/SnakeNode.hpp"

SnakeNode::SnakeNode(int x, int y) : sf::RectangleShape(
	sf::Vector2f(pixels_per_square_in_grid-2, 
	pixels_per_square_in_grid-2))
{
	setFillColor(sf::Color::White);
	setOutlineThickness(1);
	setOutlineColor(sf::Color::Black);
	setOrigin(-1,-1);
	setPosition(x * pixels_per_square_in_grid, y * pixels_per_square_in_grid);
}
