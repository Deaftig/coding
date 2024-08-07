#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "menu.h"
#include "scoreboard.h"

class engine
{
private:
	sf::RenderWindow window;
	sf::Event event;

	void initWindow();

	void input();
	void update();
	void render();

public:
	engine();
	void run();
};

#endif