#include "../Header Files/Creature.h"

//Creature has a high chance of being nothing, low chance of being something
Creature::Creature(){
    int rand = Random::get().intInRange(0, 1000);

    health = DEFAULT_HEALTH;
    reproduce = false;

    if(rand > 80) {
        setType(Nothing);
    }else if(rand > 40){
        setType(Predator);
    }else{
        setType(Prey);
    }
}

//Updates predator given another creature
//This is the creature whose position it tries to move on to
//Logic for movement is in Application.cpp Update Method
void Creature::updatePred(Creature& other) {
    //If predator dies, it becomes nothing
    if(health <= 0){
        setType(Nothing);
        health = DEFAULT_HEALTH;
    }else {

        //Checking what the other creature is
        auto otherType = other.type;
        //Loses health every update
        health--;

        //If predator, do nothing
        //If prey, eat prey, gain half of prey's health, give prey default health, and turn it into a predator
        //If nothing, move there
        switch (otherType) {
            case Predator:
                break;
            case Prey:
                health += other.health/2;
                other.health = DEFAULT_HEALTH;
                other.setType(Predator);
                break;
            case Nothing:
                move(other);
                break;

        }
        //Always updating color of cell
        setColor();
    }
}

//Updates prey given another creature
//This is the creature whose position it tries to move on to
//Logic for movement is in Application.cpp Update Method
void Creature::updatePrey(Creature &other) {
    //If health is over a certain value, Prey can reproduce
    if(health >= REPRODUCE_HEALTH) {
        reproduce = true;
    }

    //Checks the type of the cell at the position it wanted to move
    auto otherType = other.type;
    //Gains health every update
    health++;

    //If predator, do nothing
    //If prey, do nothing
    //If nothing and prey can reproduce, it turns the nothing into a new prey and reverts health to default
    //If nothing and prey cannot reproduce, it simply moves there
    switch(otherType){
        case Predator:
            break;
        case Prey:
            break;
        case Nothing:
            if(reproduce){
                other.setType(Prey);
                other.health = DEFAULT_HEALTH;
                health = DEFAULT_HEALTH;
                reproduce = false;
            }else{
                move(other);
            }
            break;
    }

    //Always updating color of cell
    setColor();
}

//Rather than changing x,y coordinates, just make the other creature have this object's
// properties and make this object a nothing tile
void Creature::move(Creature &other) {
    other.setType(type);
    setType(Nothing);
}

//getters & setters
CreatureType Creature::getType() {
    return type;
}

void Creature::setType(CreatureType type) {
    this->type = type;
    setColor();
}

//Sets color based on health amount
//Darker if health is lower, brighter if health is higher
void Creature::setColor() {
    float normalizedHealth = (float) health/  (float)REPRODUCE_HEALTH;
    int newColor;

    if(normalizedHealth > 1){
        newColor = 220;
    }else {
        newColor = int(normalizedHealth * 255);
    }

    //RBG
    //newColor goes into the reds for Predator, greens for Prey
    switch(type) {
        case Predator:
            color = sf::Color(newColor, 0, 0);
            break;
        case Prey:
            color = sf::Color(0, newColor, 0);
            break;
        case Nothing:
            color = NOTHING_COLOR;
            break;
    }
}

sf::Color Creature::getColor() {
    return color;
}