#include "globals.h"
#include "menu.h"

#include <iostream>

Menu::Menu()
{
    if (!font.loadFromFile("Fonts/Dimbo Regular.ttf"))
    {
        std::cerr << "Fehler beim Laden der Schriftart" << std::endl;
    }

    // Darstellen der Schrift im Hauptmenü
    initText(titleText, "SNAKE", 90, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.2));             // Initialisieren des Textes "SNAKE", in Abhängigkeit der Fenstergröße
    initText(startText, "START", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.4));             //          -||-             "START",              -||-        
    initText(highscoreText, "HIGHSCORE", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.5));     //          -||-             "HIGHSCORE",          -||-        
    initText(quitText, "BEENDEN", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.6));            //          -||-             "BEENDEN",            -||-        
     
    selectedItem = 0;   // "START" als ausgewählt festlegen
    updateTextColors(); // Aufruf der Funktion, welche die einzelnen Menüpunkte, je nach aktueller Auswahl, farbig hinterlegt
}

// 
void Menu::render(sf::RenderWindow& window)
{
    window.clear(gb::cBackground);
    window.draw(titleText);             // Rendern des Textes "SNAKE"
    window.draw(startText);             //      -||-          "START"
    window.draw(highscoreText);         //      -||-          "HIGHSCORE"
    window.draw(quitText);              //      -||-          "BEENDEN"
    window.display();
}

/*
Auswahl des aktuellen Menüpunktes mit den Tasten "W" und "S".
Sobald während der aktuellen Auswahl Enter gedrückt wird, wird der Menüpunkt ausgewählt.
*/
int Menu::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            selectedItem = (selectedItem - 1 + 3) % 3;
            updateTextColors();
        }
        else if (event.key.code == sf::Keyboard::S)
        {
            selectedItem = (selectedItem + 1) % 3;
            updateTextColors();
        }
        else if (event.key.code == sf::Keyboard::Enter)
        {
            if (selectedItem == 0)
            {
                return 1; // START
            }
            else if (selectedItem == 1)
            {
                return 2; // HIGHSCORE
            }
            else if (selectedItem == 2)
            {
                return 3; // BEENDEN
            }
        }
    }
    return 0;
}

void Menu::initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position)
{
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

/*
Funktion, welche nach Auswahl des Menüpunktes die Farbe des Textes ändert.
Die Farben "TextOn" und "TextOff" wird per namespace "gb" aus globals.h geholt.
*/
void Menu::updateTextColors()
{
    startText.setFillColor(selectedItem == 0 ? gb::cTextOn : gb::cTextOff);         // Ist die Auswahl 0, wird "START" hell dargestellt, wenn nicht, dann dunkel.
    highscoreText.setFillColor(selectedItem == 1 ? gb::cTextOn : gb::cTextOff);     //      -||-       1, wird "HIGHSCORE"            -||-
    quitText.setFillColor(selectedItem == 2 ? gb::cTextOn : gb::cTextOff);          //      -||-       2, wird "BEENDEN"              -||-
}
