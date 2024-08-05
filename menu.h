#ifndef menu_h
#define menu_h

// SFML-Bibliothek
#include <SFML/Graphics.hpp>

// Header-Dateien
#include "globals.h"


	class Menu
	{
	public:
		Menu();
		void render(sf::RenderWindow& window);
		int handleInput(sf::Event& event);
		void stateChange();


	private:
		sf::Font font;
		sf::Text titleText;
		sf::Text startText;
		sf::Text highscoreText;
		sf::Text quitText;
	};

#endif