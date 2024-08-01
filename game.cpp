#include "globals.h"
#include "game.h"

#include <iostream>
#include <fstream>
#include <sstream>

// Arena
const int blockSize = 20;
const int arenaWidth = 18;
const int arenaHeight = 20;

Game::Game()
    : fruit(-1, -1), score(0), direction(0), isPlaying(false), gameOver(false), enteringName(true), playerName(""), lastPlayerName(""),
    updateInterval(10.0f), timeSinceLastUpdate(0.0f){ // Updateintervall f�r angepasste Geschwindigkeit

    if (!font.loadFromFile("Fonts/Dimbo Regular.ttf")) {
        std::cerr << "Fehler beim Laden der Schriftart" << std::endl;
    }

    // Korrigierte Position f�r den Punktestand
    initText(scoreText, "Punkte: 0", 30, gb::cTextOn, sf::Vector2f(800, 20));

    initText(nameInputText, "Name: ", 30, gb::cTextOn, sf::Vector2f(gb::winWidth/2, gb::winHeight/2)); // Zentriert im Namenseingabe-Fenster
    initText(nameText, "", 30, gb::cTextOn, sf::Vector2f(gb::winWidth / 2, gb::winHeight * 0.4));

    initText(endGameText, "", 30, gb::cTextOn, sf::Vector2f(gb::winWidth/2, gb::winHeight/2)); // Zentriert im Endspiel-Fenster

    snakeShape.setSize(sf::Vector2f(blockSize, blockSize));
    snakeShape.setFillColor(gb::cSnake);

    fruitShape.setSize(sf::Vector2f(blockSize, blockSize));
    fruitShape.setFillColor(gb::cFruit);

    reset();
}

void Game::render(sf::RenderWindow& window)
{
    if (enteringName)
    {
        // Hintergrundfarbe f�r das Namenseingabe-Fenster
        window.clear(gb::cBackground); // Hintergrundfarbe des Namenseingabe-Fensters
        window.draw(nameInputText);
    }
    else if (gameOver)
    {
        // Hintergrundfarbe f�r das Endspiel-Fenster
        window.clear(gb::cShade); // Hintergrundfarbe des Endspiel-Fensters
        window.draw(endGameText);
    }
    else
    {
        // Hintergrundfarbe f�r das Spiel-Fenster
        window.clear(gb::cBackground);

        // Arena zeichnen
        sf::RectangleShape arenaShape;
        arenaShape.setSize(sf::Vector2f(arenaWidth * blockSize, arenaHeight * blockSize)); // Gr��e der Arena ( ArenaBreite * BlockGr�0e, ArenaH�he * BlockGr��e )
        arenaShape.setPosition((gb::winWidth - arenaWidth * blockSize) / 2, (gb::winHeight - arenaHeight * blockSize) / 2); // 
        arenaShape.setFillColor(gb::cTextOn);
        window.draw(arenaShape);

        window.draw(scoreText);

        for (const auto& segment : snake)
        {
            snakeShape.setPosition(segment.x * blockSize, segment.y * blockSize);
            window.draw(snakeShape);
        }

        fruitShape.setPosition(fruit.x * blockSize, fruit.y * blockSize);
        window.draw(fruitShape);
    }

    window.display();
}

int Game::handleInput(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (enteringName)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                if (!playerName.empty())
                {
                    enteringName = false;
                    isPlaying = true;
                    lastPlayerName = playerName;
                }
            }
            else if (event.key.code == sf::Keyboard::BackSpace && !playerName.empty())
            {
                playerName.pop_back();
                nameText.setString(playerName);
            }
        }
        else if (gameOver)
        {
            if (event.key.code == sf::Keyboard::Enter)
            {
                reset();
            }
            else if (event.key.code == sf::Keyboard::Escape)
            {
                return 0; // Zur�ck zum Men�
            }
        }
        else
        {
            if (event.key.code == sf::Keyboard::W && direction != 2) direction = 0; // Up
            else if (event.key.code == sf::Keyboard::D && direction != 3) direction = 1; // Right
            else if (event.key.code == sf::Keyboard::S && direction != 0) direction = 2; // Down
            else if (event.key.code == sf::Keyboard::A && direction != 1) direction = 3; // Left
            else if (event.key.code == sf::Keyboard::Escape) return 0; // Zur�ck zum Men�
        }
    }
    else if (event.type == sf::Event::TextEntered && enteringName)
    {
        if (event.text.unicode < 128 && std::isprint(event.text.unicode))
        {
            playerName += static_cast<char>(event.text.unicode);
            nameText.setString(playerName);
        }
    }

    return -1;
}

void Game::update() {
    if (!isPlaying || gameOver) return;

    timeSinceLastUpdate += 0.1f; // Simulate time elapsed

    if (timeSinceLastUpdate >= updateInterval) {
        timeSinceLastUpdate = 0.0f;
        moveSnake();

        if (checkCollision()) {
            gameOver = true;
            isPlaying = false;
            saveScore();
            endGameText.setString("Spiel beendet! " + playerName + ": " + std::to_string(score) + " Punkte\nDr�cke Enter zum Neustart oder Escape zum Verlassen");
            endGameText.setOrigin(endGameText.getLocalBounds().width / 2, endGameText.getLocalBounds().height / 2);
        }

        if (snake.front().x == fruit.x && snake.front().y == fruit.y) {
            snake.push_back(SnakeSegment(fruit.x, fruit.y));
            score += 1; // Einen Punkt pro Frucht
            scoreText.setString("Punkte: " + std::to_string(score));
            generateFruit();
        }
    }
}

void Game::reset() {
    snake.clear();
    snake.push_back(SnakeSegment(arenaWidth / 2, arenaHeight / 2));
    direction = 0;
    score = 0;
    scoreText.setString("Punkte: 0");
    generateFruit();
    isPlaying = false;
    gameOver = false;
    enteringName = true;
    playerName = lastPlayerName;
    nameText.setString(playerName);
}

void Game::initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position) {
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}

void Game::moveSnake() {
    for (int i = snake.size() - 1; i > 0; --i) {
        snake[i] = snake[i - 1];
    }

    if (direction == 0) snake[0].y -= 1;
    else if (direction == 1) snake[0].x += 1;
    else if (direction == 2) snake[0].y += 1;
    else if (direction == 3) snake[0].x -= 1;

    // Sicherstellen, dass die Schlange innerhalb der Arena bleibt
    if (snake[0].x < 0) snake[0].x = 0;
    else if (snake[0].x >= arenaWidth) snake[0].x = arenaWidth - 1;
    if (snake[0].y < 0) snake[0].y = 0;
    else if (snake[0].y >= arenaHeight) snake[0].y = arenaHeight - 1;
}

void Game::generateFruit() {
    // Sicherstellen, dass die Frucht nicht auf der Schlange erscheint
    bool validPosition = false;
    while (!validPosition) {
        fruit.x = rand() % arenaWidth;
        fruit.y = rand() % arenaHeight;

        validPosition = true;
        for (const auto& segment : snake) {
            if (segment.x == fruit.x && segment.y == fruit.y) {
                validPosition = false;
                break;
            }
        }
    }
}

bool Game::checkCollision() {
    // Kollision mit den Arena-Grenzen
    if (snake.front().x < 0 || snake.front().x >= arenaWidth || snake.front().y < 0 || snake.front().y >= arenaHeight) {
        return true;
    }

    // Kollision mit sich selbst
    for (int i = 1; i < snake.size(); ++i) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            return true;
        }
    }

    return false;
}

void Game::saveScore() {
    std::ofstream file("scoreboard.txt", std::ios::app);
    if (file.is_open()) {
        file << playerName << " " << score << "\n";
        file.close();
    }
}



