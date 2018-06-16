#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "include/Config.hpp"
#include "include/GameController.hpp"
#include "include/Maca.hpp"
#include "include/Snake.hpp"

int main()
{
	bool isRunning = true;
	sf::Text score;
	sf::Font font;
	if ( !font.loadFromFile("font/fipps.otf") )
	{
		std::cout << "Falha ao carregar a font\n";
	}
	score.setFont(font);
	char string_score[50];

	Snake snake((int)(largura/2), (int)(altura/2));
	Maca maca;
	while ( snake.isOverMe(maca) )
		maca.sortPosition();
	sf::RenderWindow window(sf::VideoMode(largura_in_pixels, altura_in_pixels), "Snake");
	window.setFramerateLimit(60);
	GameController gamecontroller(&snake, &maca, &window);
	
	score.setFillColor(sf::Color::Yellow);
	score.setCharacterSize(10);
	score.setPosition(5,5);
	
	sf::Clock frameClock;
	while(window.isOpen())
	{
		sf::Time frameTime = frameClock.restart();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        gamecontroller.update(frameTime);
        
        if ( snake.length() == MAX_length )
        {
        	if ( isRunning )
        	{
        		sprintf(string_score, "Voce eh foda\n   score: %d", snake.length());
        		score.setString(string_score);
        		score.setCharacterSize(20);
        		score.setPosition(largura_in_pixels/2 - 100, altura_in_pixels/2 - 40);
        		window.clear();
        		window.draw(maca);
        		window.draw(snake);
        	}
        	window.draw(score);
        	window.display();
        	isRunning = false;
        }

        if ( snake.selfCannibalism() )
        {
        	if ( isRunning )
        	{
        		sprintf(string_score, "Acabou!\nscore: %d", snake.length());
        		score.setString(string_score);
        		score.setCharacterSize(20);
        		score.setPosition(largura_in_pixels/2 - 70, altura_in_pixels/2 - 40);
        		window.clear();
        		window.draw(maca);
        		window.draw(snake);
        	}
        	window.draw(score);
        	window.display();
        	isRunning = false;
        }

        if ( isRunning )
        {
        	sprintf(string_score, "score: %d", snake.length());
        	score.setString(string_score);
        	window.clear();
        	window.draw(maca);
        	window.draw(snake);
        	window.draw(score);
        	window.display();
        }
    }
}
