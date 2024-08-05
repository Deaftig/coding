#include "menu.h"

	Menu::Menu()
	{

	}

	void Menu::render(sf::RenderWindow& window)
	{
		window.clear(gb::cBackground);
		window.draw(titleText);             // Rendern des Textes "SNAKE"
		window.draw(startText);             //      -||-          "START"
		window.draw(highscoreText);         //      -||-          "HIGHSCORE"
		window.draw(quitText);              //      -||-          "BEENDEN"
		window.display();
	}
	int Menu::handleInput(sf::Event& event)
	{
		return 0;
	}

	void Menu::stateChange()
	{
		while 
	};

