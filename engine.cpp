#include "engine.h"
#include "globals.h"

void engine::initWindow()
{
	window.create(sf::VideoMode(gb::winWidth, gb::winHeight), "LUMALU", sf::Style::None);
	window.setFramerateLimit(60);
}

void engine::input()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				window.close();
		}
	}
}


void engine::update()
{
}

void engine::render()
{
	window.clear();
}

// Public
engine::engine()
{
	initWindow();
}

void engine::run()
{
	while (window.isOpen())
	{
		input();
		update();
		render();
	}
}
