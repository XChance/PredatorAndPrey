#ifndef PREDATOR_AND_PREY_APPLICATION_H
#define PREDATOR_AND_PREY_APPLICATION_H

#include "SFML/Graphics.hpp"
#include "../Header Files/Automaton.h"

class Application{
public:
    Application();

    void run();

    static const int WIDTH = 800, HEIGHT = 800;

private:
    void update();
    void render();
    void pollEvents();

    sf::RenderWindow renderWindow;

    sf::View windowView;

    //The object that handles the Automaton's logic
    Automaton automaton;
    bool paused;
};

#endif //PREDATOR_AND_PREY_APPLICATION_H
