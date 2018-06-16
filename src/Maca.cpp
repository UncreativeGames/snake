#include "../include/Maca.hpp"
#include <time.h>
#include <cmath>

Maca::Maca() : sf::RectangleShape(
	sf::Vector2f(pixels_per_square_in_grid-2, 
	pixels_per_square_in_grid-2))
{
	setFillColor(sf::Color::Red);
	setOutlineThickness(1);
	setOutlineColor(sf::Color::Black);
	setOrigin(-1,-1);
	sortPosition();
}

void Maca::sortPosition()
{
	srand(time(NULL));
	int x = rand() % largura;
	int y = rand() % altura;
	setPosition(x * pixels_per_square_in_grid, y * pixels_per_square_in_grid);
}
