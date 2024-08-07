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
			break;
		}
	}
}


void engine::update()
{
}

void engine::render()
{
	window.clear(gb::colBackground); // just for testing, still need a switch, which state is to be rendered
	window.display();
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
