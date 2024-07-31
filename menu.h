#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu();
    ~Menu();
    void render(sf::RenderWindow& window);
    int handleInput(sf::Event& event);

private:
    sf::Font font;
    sf::Text titleText;
    sf::Text startText;
    sf::Text highscoreText;
    sf::Text quitText;
    int selectedItem;

    void initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position);
    void updateTextColors();
};

#endif // MENU_H
