#ifndef GLOBALS.H
#define GLOBALS.H

#include "bib.h"

namespace gb
{
	// Farben
	// Frucht

	const sf::Color cFruit(202, 83, 51); // Rot

	// Schrift
	const sf::Color cTextOff(200, 200, 200); // Grau
	const sf::Color cTextOn(255, 255, 255);  // Weiß

	// Schlange
	const sf::Color cSnake(94, 115, 223, 255);	// Blau

	// Farbschema
	const sf::Color cBackground(51, 70, 118, 255);	// Blau
	const sf::Color cSecondary(66, 91, 157, 255);	// Blau

	//Arena
	const sf::Color cArena1(188, 206, 244, 255);	// Blau
	const sf::Color cArena2(173, 195, 239, 255);	// Blau

	//Schatten
	const sf::Color cShade(20, 20, 20, 10);	// Grau 10%


	// Fenstergröße
	const int winWidth = 600;
	const int winHeight = 600;

	// Arena
	const int blockSize = 30;
	const int arenaWidth = 18;
	const int arenaHeight = 16;
}

#endif