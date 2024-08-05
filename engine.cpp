// Header-Dateien
#include "engine.h"
#include "globals.h"

Engine::Engine() {
    initVariables();
    initWindow();
    initInput();
}

void Engine::initVariables() {
    gameState = stateMenu;
}

void Engine::initWindow() {
    // Erzeugen des Fensters
    window.create(sf::VideoMode(gb::winWidth, gb::winHeight), "SNAKE by LUMALU", sf::Style::None);
    window.setFramerateLimit(60);
}

void Engine::initInput() {
    // Initialisierung der Eingabe
}

void Engine::handleInput() {
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Engine::update() {
    // Aktualisierungslogik basierend auf dem Spielstatus
}

void Engine::render() {
    window.clear();

    switch (gameState) {
    case stateMenu:
        menu.render(window);
        break;
    case stateGameplay:
        game.render(window);
        break;
    case stateScoreboard:
        scoreboard.render(window);
        break;
    default:
        menu.render(window);
        break;
    }

    window.display();
}

void Engine::run() {
    while (window.isOpen()) {
        handleInput();
        update();
        render();
    }
}
