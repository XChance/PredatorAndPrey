# Predator and Prey

This is my version of the Predator and Prey Cellular Automaton. This was largely inspired by Hopson97.

I'd like to quickly give Hopson97 kudos, as his version helped to give me an idea of how I could handle each cell. In addition,
I used his files for Random Number Generation as his is far bette than my own previous implementation.

##Automaton Rules

Each cell is 4 x 4 Pixels.
One cell represents a creature.

**Black cells** are dead/nothing
**Green cells** are Prey
**Red cells** are Predators

Every **living** cell moves randomly with each update.

**Predators:**
Lose health every tick
If it tries to move onto a prey, the predator gains half of the prey’s health and turns the prey into a predator (Predator reproduction)
If it tries to move onto a fellow predator, then it does nothing.
If it tries to move onto nothing then it does.

**Prey:**
Gain health every tick
Once health reaches a certain threshold, they can reproduce
If it tries to move onto nothing and it is able to reproduce, then it creates a new Prey cell on the dead tile instead.
If it tries to move onto nothing and it cannot reproduce, then it does.
If it tries to move onto a Predator or Prey cell, then it does nothing.
