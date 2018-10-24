#ifndef PREDATOR_AND_PREY_CREATURE_H
#define PREDATOR_AND_PREY_CREATURE_H

#include "SFML/Graphics.hpp"
#include "../Header Files/Random.h"
#include "string"

//Enum Creature type. Every Cell in sim is a Creature, majority are Nothing
enum CreatureType{
    Nothing = 0,
    Predator = 1,
    Prey = 2
};

class Creature{
public:
    Creature();
 
    //Update predator or prey
    void updatePred(Creature& other);
    void updatePrey(Creature& other);

    CreatureType getType();
    sf::Color getColor();

private:
    void move(Creature& other);
    void setType(CreatureType type);
    void setColor();

    //Values for cell logic
    bool reproduce;
    int health;
    const int DEFAULT_HEALTH = 5, REPRODUCE_HEALTH = 14;

    const sf::Color NOTHING_COLOR = sf::Color::Black;
    sf::Color color;

    CreatureType type;
};

#endif //PREDATOR_AND_PREY_CREATURE_H
