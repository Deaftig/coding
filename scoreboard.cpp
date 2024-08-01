#include "globals.h"
#include "scoreboard.h"

#include <fstream>
#include <algorithm>
#include <sstream>
#include <iostream>

Scoreboard::Scoreboard()
    : displayingScores(true), waitingForDeleteConfirmation(false), nameToDelete("") {

    if (!font.loadFromFile("Fonts/Dimbo Regular.ttf")) {
        std::cerr << "Fehler beim Laden der Schriftart" << std::endl;
    }

    initText(scoreboardText, "", 30, gb::cTextOn, sf::Vector2f(400, 50));
    initText(deleteText, "Dr�cke Enter zum L�schen der Highscores", 30, gb::cTextOn, sf::Vector2f(400, 550));
    initText(highscoreText, "Highscores", 50, gb::cTextOn, sf::Vector2f(400, 10));

    loadScores();
}

void Scoreboard::render(sf::RenderWindow& window) {
    window.clear(gb::cBackground);
    window.draw(highscoreText);

    if (displayingScores) {
        window.draw(scoreboardText);

        if (waitingForDeleteConfirmation) {
            window.draw(deleteText);
        }
    }

    window.display();
}

int Scoreboard::handleInput(sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            return 0; // Zur�ck zum Men�
        }
        if (event.key.code == sf::Keyboard::Enter) {
            if (waitingForDeleteConfirmation) {
                clearScores();
                loadScores();
                displayingScores = true;
                waitingForDeleteConfirmation = false;
            }
            else {
                displayingScores = !displayingScores;
                waitingForDeleteConfirmation = !displayingScores;
            }
        }
    }
    return -1;
}

void Scoreboard::loadScores() {
    scores.clear();
    std::ifstream file("scoreboard.txt");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name;
        int score;
        if (iss >> name >> score) {
            scores.emplace_back(name, score);
        }
    }
    file.close();

    // Sortieren nach Punktestand absteigend
    std::sort(scores.begin(), scores.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second;
        });

    // Nur die obersten 10 Eintr�ge anzeigen
    std::ostringstream oss;
    for (size_t i = 0; i < std::min(scores.size(), static_cast<size_t>(10)); ++i) {
        oss << scores[i].first << ": " << scores[i].second << "\n";
    }
    if (scores.empty()) {
        oss << "Keine Eintr�ge vorhanden";
    }

    scoreboardText.setString(oss.str());
}

void Scoreboard::saveScores() {
    std::ofstream file("scoreboard.txt", std::ios::app);
    if (file.is_open()) {
        file << nameToDelete << " " << 0 << "\n"; // Beispiel, hier k�nnte der neue Punktestand eingetragen werden
        file.close();
    }
}

void Scoreboard::addScore(const std::string& name, int score) {
    scores.emplace_back(name, score);
    std::ofstream file("scoreboard.txt", std::ios::app);
    if (file.is_open()) {
        file << name << " " << score << "\n";
        file.close();
    }
    loadScores(); // Update die Anzeige nach dem Hinzuf�gen
}

void Scoreboard::clearScores() {
    std::ofstream file("scoreboard.txt", std::ios::trunc);
    if (file.is_open()) {
        file.close();
    }
    scores.clear();
}

void Scoreboard::initText(sf::Text& text, const std::string& string, unsigned int size, sf::Color color, sf::Vector2f position) {
    text.setFont(font);
    text.setString(string);
    text.setCharacterSize(size);
    text.setFillColor(color);
    text.setPosition(position);
    text.setOrigin(text.getLocalBounds().width / 2, text.getLocalBounds().height / 2);
}
