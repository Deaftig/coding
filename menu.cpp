#include "globals.h"
#include "menu.h"

#include <iostream>

Menu::Menu()
{
    if (!font.loadFromFile("Fonts/Dimbo Regular.ttf"))
    {
        std::cerr << "Fehler beim Laden der Schriftart" << std::endl;
    }

    initText(titleText, "SNAKE", 90, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.2));
    initText(startText, "START", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.4));
    initText(highscoreText, "HIGHSCORE", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.5));
    initText(quitText, "BEENDEN", 50, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.6));

    selectedItem = 0;
    updateTextColors();
}

void Menu::render(sf::RenderWindow& window)
{
    window.clear(gb::cBackground);
    window.draw(titleText);
    window.draw(startText);
    window.draw(highscoreText);
    window.draw(quitText);
    window.display();
}

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

void Menu::updateTextColors()
{
    startText.setFillColor(selectedItem == 0 ? gb::cTextOn : gb::cTextOff);
    highscoreText.setFillColor(selectedItem == 1 ? gb::cTextOn : gb::cTextOff);
    quitText.setFillColor(selectedItem == 2 ? gb::cTextOn : gb::cTextOff);
}
