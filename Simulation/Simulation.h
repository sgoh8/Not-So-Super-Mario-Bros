/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Mario.h"
#include "Game.h"
#include "World.h"
#include <string>

class Simulation {
    public: 
        Simulation(Game game, std::string logFileName);
        ~Simulation();

        void run();

    private: 
        Game game; 
        World world; 
        Mario mario;
        std::ofstream logFile;
        int moves;
};

#endif