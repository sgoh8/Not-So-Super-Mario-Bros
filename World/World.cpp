/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "World.h"


World::World(Game game) {   // constructor
    numOfLevels = game.getNumOfLevel();    
    gridN = game.getGridSize();

    bool warp = false;

    levels = new Level*[numOfLevels];    
    for (int l = 0; l < numOfLevels; l++) {
        if (l < (numOfLevels - 1)) {    // check if the level is less than the last level, then set warp to false to randomly have a warp pipe in the grid otherwise set warp to true
            warp = false;
        } else {
            warp = true;
        }

        levels[l] = new Level(game, gridN, warp);
    }
}

World::~World() {
    for(int l = 0; l < numOfLevels; l++) {
        delete[] levels[l];
    }
    delete[] levels;

}

char World::getTile(int curLevel, int r, int c) {
    return levels[curLevel].getTile(r,c);
}

void World::setTile(int level, int r, int c, char object) {
    levels[level].setTile(r, c, object);
}

void World::printMario(int level, Mario mario) {
    levels[level].print(mario, level);
}