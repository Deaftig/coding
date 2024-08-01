#ifndef GAME_H
#define GAME_H


#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

struct SnakeSegment
{
    int x, y;
    SnakeSegment(int x, int y) : x(x), y(y) {}
};

class Game
{
public:
    Game();
    void render(sf::RenderWindow& window);
    int handleInput(sf::Event& event);
    void update();
    void reset();

private:
    void initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position);
    void moveSnake();
    void generateFruit();
    bool checkCollision();
    void saveScore();

    sf::Font font;
    sf::Text scoreText;
    sf::Text nameInputText;
    sf::Text nameText;
    sf::Text endGameText;

    sf::RectangleShape snakeShape;
    sf::RectangleShape fruitShape;

    int score;
    int direction;
    bool isPlaying;
    bool gameOver;
    bool enteringName;
    std::string playerName;
    std::string lastPlayerName;

    SnakeSegment fruit;
    std::vector<SnakeSegment> snake;

    float updateInterval;
    float timeSinceLastUpdate;
};

#endif