#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

class Scoreboard
{
public:
    Scoreboard();
    void render(sf::RenderWindow& window);
    int handleInput(sf::Event& event);
    void loadScores();
    void saveScores();
    void addScore(const std::string& name, int score);
    void clearScores();

private:
    std::vector<std::pair<std::string, int>> scores;
    sf::Font font;
    sf::Text scoreboardText;
    sf::Text deleteText;
    sf::Text backText;
    sf::Text highscoreText;
    std::string nameToDelete;

    bool displayingScores;
    bool waitingForDeleteConfirmation;
    int selectedItem;

    void initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position);
    void updateTextColors();


};

#endif // SCOREBOARD_H
