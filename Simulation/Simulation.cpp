/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "Simulation.h"
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

Simulation::Simulation(Game g, std::string logFileName) {
    game = g; // initialise game
    moves = 0; // initialise moves to 0

    srand(time(0)); // seed the random number generator

    world = World(game); // create the world
    mario = Mario(rand() % game.getGridSize(), rand() % game.getGridSize(), game.getInitialLives()); // create mario at a random position in the grid with initial lives

    logFile.open(logFileName); // open the log file
    if (!logFile) { // check if the log file was created successfully
        std::cout << "Error creating log file" << std::endl;
    }
}

Simulation::~Simulation() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Simulation::run() {
    bool gameOver = false;

    while (gameOver == false) {
        int currentLevel = mario.getCurLevel() - 1; // get the current level of mario (0-indexed)
        world.printMario(currentLevel, mario); // print the current level with mario's position
        world.getTile(currentLevel, mario.getRow(), mario.getCol()); // get the tile that mario is currently on

        if (mario.getCurLives() <= 0) {
            gameOver = true;
            logFile << "Game over!" << std::endl;

        } else if (mario.getCurLevel() > game.getNumOfLevel()) {
            logFile << "Mario has completed all levels!" << std::endl;
            gameOver = true;
        } else {
            mario.moveRandom(game.getGridSize(), logFile); // move mario randomly
        }
    }
    
}