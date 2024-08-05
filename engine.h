#ifndef engine_h
#define engine_h

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "game.h"
#include "globals.h"
#include "menu.h"
#include "scoreboard.h"

namespace state {
	enum GameState { Menu = 0, Gameplay = 1, Scoreboard = 2 };
	enum GameState gameState = Menu;
}

	class Engine
	{
	private:

		sf::RenderWindow window;
		sf::Event event;

		void initVariables();
		void initWindow();
		void initInput();
		void menuState();
		void gameState();
		void ScoreboardState();

		void handleInput();
		void update();
		void render();

		Menu menu;
		Game game;
		Scoreboard scoreboard;

	public:

		Engine();
		void run();
	};


#endif