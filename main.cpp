/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "Simulation.h"
#include <iostream>
int main (int argc, char* argv[]) {
    /* int numOfLevels = std::stoi(argv[1]);   // convert string to integer
    int gridSize = std::stoi(argv[2]);
    int initialLives = std::stoi(argv[3]);
    int coinsPerc = std::stoi(argv[4]);
    int nothingPerc = std::stoi(argv[5]);
    int goombasPerc = std::stoi(argv[6]);
    int koopasPerc = std::stoi(argv[7]);
    int mushPerc = std::stoi(argv[8]); */ 

    std::string inputFile = argv[1];
    std::string logFile = "log.txt";

    Game game(inputFile); // create game object
    Simulation sim (game, logFile); // create simulation object
    sim.run();  // run the simulation

    return 0;
}