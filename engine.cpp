// Header-Dateien
#include "engine.h"
#include "globals.h"


	Engine::Engine()
	{
		initVariables();
		initWindow();
		initInput();
	}

	void Engine::initVariables()
	{
	}

	void Engine::initWindow()
	{
		// Erzeugen des Fensters
		sf::RenderWindow window(sf::VideoMode(gb::winWidth, gb::winHeight), "SNAKE by LUMALU", sf::Style::None);
		window.setFramerateLimit(60);
	}

	void Engine::initInput()
	{

	}

	void Engine::menuState()
	{

	}

	void Engine::gameState()
	{

	}

	void Engine::ScoreboardState()
	{

	}
	
	void Engine::handleInput()
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}

	void Engine::update()
	{

	}

	void Engine::render()
	{
		window.clear();

		switch (state::gameState)
		{
		default:
			menu.render(window);
			break;
		case state::Gameplay:
			game.render(window);
			break;
		case state::Scoreboard:
			scoreboard.render(window);
			break;
		}
		window.display();
	}

	void Engine::run()
	{
		while (window.isOpen())
		{
			handleInput();
			update();
			render();
		}
	};
