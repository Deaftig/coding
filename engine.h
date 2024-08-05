#ifndef ENGINE_H
#define ENGINE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "game.h"
#include "globals.h"
#include "menu.h"
#include "scoreboard.h"

class Engine {
private:
    sf::RenderWindow window;
    sf::Event event;

    enum GameState { stateMenu = 0, stateGameplay = 1, stateScoreboard = 2 };
    GameState gameState;

    void initVariables();
    void initWindow();
    void initInput();

    void handleInput();
    void update();
    void render();

    Menu menu;
    Game game;
    Scoreboard scoreboard;

public:
    Engine();
    void run();
};

#endif // ENGINE_H
