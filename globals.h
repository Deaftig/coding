#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>

namespace gb
{
	// Farben
	// Frucht
	const sf::Color colFruit(202, 83, 51);

	// Schrift
	const sf::Color colTextOff(200, 200, 200);
	const sf::Color colTextOn(255, 255, 255);

	// Schlange
	const sf::Color colSnake(94, 115, 223, 255);

	// Farbschema
	const sf::Color colBackground(51, 70, 118, 255);
	const sf::Color colSecondary(66, 91, 157, 255);

	//Arena
	const sf::Color colArena1(188, 206, 244, 255);
	const sf::Color colArena2(173, 195, 239, 255);

	//Schatten
	const sf::Color colShade(20, 20, 20, 10);

	// Fenstergröße
	const int winWidth = 600;
	const int winHeight = 600;

	// Arena
	const int blockSize = 30;
	const int arenaWidth = 18;
	const int arenaHeight = 16;
}

#endif