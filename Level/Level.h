/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#ifndef LEVEL_H
#define LEVEL_H

#include "Mario.h"
#include "Game.h"
#include <iostream>
#include <fstream>

class Level {
    public:
        Level(Game game, int gridN, bool warp);
        ~Level();   // destructor 

        char getTile(int r, int c);
        void setTile(int r, int c, char object);
        void interact(Mario mario, int level, std::ofstream logFile);
        void print(Mario mario, int level);

    private:
        int size; 
        char** grid;

};

#endif