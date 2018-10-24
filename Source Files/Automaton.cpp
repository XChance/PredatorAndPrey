#include "../Header Files/Automaton.h"

//Define size of creatures and cellVertices
Automaton::Automaton() : creatures(WIDTH * HEIGHT){
    cellForEach([&](int x, int y){
        addQuad(x, y);
    });
}

//Update method
void Automaton::update() {
    //For each Cell
    cellForEach([&](int x, int y){
        //Get creature at given index
        int index = getCellIndex(x, y);
        Creature &current = creatures[index];
        auto currentType = current.getType();

        //No need to update a cell that's isn't predator or prey
        if(currentType != CreatureType::Nothing) {

            //Choose a random square to move to
            int newX, newY, randX, randY;

            do {
                randX = Random::get().intInRange(-1, 1);
                randY = Random::get().intInRange(-1, 1);
            }while((randX == 0 && randY == 0) || (x + randX > 800 || x + randX < 0)
                   || (y + randY > 600 || y + randY < 0));

            newX = x + randX;
            newY = y + randY;

            //Get the Creature at the initial Creature's new position
            int otherIndex = getCellIndex(newX, newY);
            Creature &other = creatures[otherIndex];

            //Update based on whether initial Creature is a Predator or not
            switch (currentType) {
                case Predator:
                    creatures[index].updatePred(other);
                    break;
                case Prey:
                    creatures[index].updatePrey(other);
                    break;
                default:
                    break;
            }

            //Finally, change the colors being represented by cellVertices
            setCellColor(x, y, creatures[index].getColor());
        }
    });
}

//SFML Method. Given a vector of SFML Vertex, this somehow works.
//Since I indicate Quads are being drawn, it looks for each corner of the
//Square, hence why cellVertices' size is (WIDTH * HEIGHT * 4)
void Automaton::render(sf::RenderWindow &renderWindow) {
   renderWindow.draw(cellVertices.data(), cellVertices.size(), sf::Quads);
}

//Changes color of 4 cell vertices (1 quad), given an X and Y index and a Color
void Automaton::setCellColor(int xIndex, int yIndex, sf::Color color) {
    int index = getCellIndex(xIndex, yIndex) * 4;
    for (int i = 0; i < 4; i++) {
        cellVertices[index + i].color = color;
    }
}

//Adds a Quad to the cellVertices vector. Quads are made up of
//4 Vertices which just have a position and color.
void Automaton::addQuad(int xIndex, int yIndex) {
    sf::Vertex topLeft;
    sf::Vertex topRight;
    sf::Vertex bottomLeft;
    sf::Vertex bottomRight;

    float pixelX = xIndex * CELL_SIZE;
    float pixelY = yIndex * CELL_SIZE;

    topLeft.position = { pixelX, pixelY };
    topRight.position = { pixelX + CELL_SIZE, pixelY };
    bottomLeft.position = { pixelX, pixelY + CELL_SIZE };
    bottomRight.position = { pixelX + CELL_SIZE, pixelY + CELL_SIZE };

    topLeft.color = sf::Color::Black;
    topRight.color = sf::Color::Black;
    bottomLeft.color = sf::Color::Black;
    bottomRight.color = sf::Color::Black;

    cellVertices.push_back(topLeft);
    cellVertices.push_back(bottomLeft);
    cellVertices.push_back(bottomRight);
    cellVertices.push_back(topRight);
}