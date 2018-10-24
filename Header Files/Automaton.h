#ifndef PREDATOR_AND_PREY_AUTOMATON_H
#define PREDATOR_AND_PREY_AUTOMATON_H

#include <vector>

#include "SFML/Graphics.hpp"
#include "../Header Files/Random.h"
#include "Creature.h"

class Automaton {
public:
    Automaton();

    //Cell will be 4 pixels wide and long
    //Width & Height of Window (Application.cpp) are divided by cell size
    static const int CELL_SIZE = 4;
    static const int WIDTH = 800/CELL_SIZE, HEIGHT = 800/CELL_SIZE;

    //Update and render methods
    void update();
    void render(sf::RenderWindow& renderWindow);

private:
    //Cell handling methods
    void addQuad(int xIndex, int yIndex);
    void setCellColor(int xIndex, int yIndex, sf::Color color);

    //Each cell is a set of vertices. One for each corner of the square that represents it.
    //So cellVertices is (WIDTH * HEIGHT * 4).
    //Creatures is a vector of Creature objects (Creature.cpp), which represent each cell
    std::vector<sf::Vertex> cellVertices;
    std::vector<Creature> creatures;


    //Helpful methods
    //GetCellIndex returns the index of a vector given the x and y of a for loop
    template<typename Func> void cellForEach(Func function);

    int getCellIndex(int x, int y){
        return x + y * WIDTH ;
    }

};

//For each cell template. Method function defined within it
template<typename Func>
void Automaton::cellForEach(Func function)
{
    for (unsigned x = 0; x < WIDTH; x++) {
        for (unsigned y = 0; y < HEIGHT; y++) {
            function(x, y);
        }
    }

}

#endif //PREDATOR_AND_PREY_AUTOMATON_H
