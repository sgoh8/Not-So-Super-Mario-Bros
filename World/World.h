/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#ifndef WORLD_H
#define WORLD_H

#include "Game.h"
#include "Mario.h"
#include <iostream>
#include "Level.h"


class World {
    public: 
        World(Game game);   // constructor 
        ~World();   // destructor 

        char getTile(int level, int r, int c);
        void setTile(int level, int r, int c, char object);
        void printMario(int level, Mario mario);

    private:
        int numOfLevels;
        int gridN; 
        char*** grid;   // dynamic 3d array (numOfLevel x gridN x gridN)
        Level** levels;

};

#endif