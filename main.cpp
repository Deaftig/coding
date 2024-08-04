#include "globals.h"
#include "menu.h"               // Inkludieren der Datei "menu.h"
#include "game.h"               // Inkludieren der Datei "game.h"
#include "scoreboard.h"

#include <SFML/Graphics.hpp>    // Inkludieren der SFML-Bibliothek f�r Grafische Anwendungen

// Hauptschleife
void main()
{
    // Erzeugen des Fensters
    sf::RenderWindow window(sf::VideoMode(gb::winWidth, gb::winHeight), "SNAKE by LUMALU", sf::Style::None);

    // Initialiseren der Unterprogramme
    Menu menu;               // Initialiseren des Hautpmen�s
    Game game;               // Initialiseren des Spiels
    Scoreboard scoreboard;   // Initialsieren des Scoreboards

    // Auswahl, in welchem Unterprogramm gestartet wird
    int state = 0; // 0: Hauptmen�, 1: Spiel, 2: Highscore

    // while-Schleife, welche l�uft, solange das Fenster ge�ffnet ist
    while (window.isOpen())
    {
        sf::Event event;    // Festlegen, dass die SFML-Event-Funktion "Event" alle Eingaben an die Variable "event" �bergibt
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (state == 0) // Auswahl des Unterprogramms Menu
            {
                int result = menu.handleInput(event); // �bergabe des Inputs an das Unterprogramm Menu
                if (result == 1) state = 1; // Spiel starten
                else if (result == 2) state = 2; // Highscore anzeigen
                else if (result == 3) window.close(); // Beenden
            }
            else if (state == 1) // Auswahl des Unterprogramms Game
            {
                int result = game.handleInput(event); // �bergabe des Inputs an das Unterprogramm Game
                if (result == 0) state = 0; // Zur�ck zum Hauptmen�
            }
            else if (state == 2) // Auswahl des Unterprogramms Scoreboard
            {
                int result = scoreboard.handleInput(event); // �bergabe des Inputs an das Unterprogramm Scoreboard
                if (result == 0) state = 0; // Zur�ck zum Hauptmen�
            }
        }

        // Unterprogramm = Menu -> Anzeigen Menu
        if (state == 0)
        {
            menu.render(window);
        }

        // Unterprogramm = Game -> Anzeigen Game
        else if (state == 1)
        {
            game.update();
            game.render(window);
        }

        // Unterprogramm = Scoreboard -> Anzeigen Scoreboard
        else if (state == 2)
        {
            scoreboard.render(window);
        }
    }
}
