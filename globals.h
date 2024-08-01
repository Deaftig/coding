#ifndef GLOBALS_H
#define GLOBALS_H

#include <SFML/Graphics.hpp>
namespace gb
{
	// Farben
	// Frucht
	const sf::Color cFruit(202, 83, 51);
	// Schrift
	const sf::Color cTextOff(200, 200, 200);
	const sf::Color cTextOn(255, 255, 255);
	// Schlange
	const sf::Color cSnake(94, 115, 223, 255);
	// Farbschema
	const sf::Color cBackground(51, 70, 118, 255);
	const sf::Color cSecondary(66, 91, 157, 255);
	//Arena
	const sf::Color cArena1(188, 206, 244, 255);
	const sf::Color cArena2(173, 195, 239, 255);
	//Schatten
	const sf::Color cShade(50, 50, 50, 10);

	// Fenstergröße
	const int winWidth = 600;
	const int winHeight = 600;
}

#endif