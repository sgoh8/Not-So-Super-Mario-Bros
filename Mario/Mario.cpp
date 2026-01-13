/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "Mario.h" 
#include <cstdlib>

Mario::Mario(int r, int c, int initialLives) {  // constructor
    curLevel = 1;
    row = r;
    col = c;
    curLives = initialLives;
    power = 0;  // start with PL0
    coins = 0;  // start with 0 coins
    numOfEnemiesDefeated = 0;   // start with 0 enemies
    
}

Mario::~Mario() {} // destructor

void Mario::increasePower() {   // check if power level is less than 2, then increase power level by 1
    if (power < 2) {
        power++;
    }
}

void Mario::decreasePower() {   // check if power is more than 0, then decrease power. otherwise, mario lose a life
    if (power > 0) {
        power --;
    } else {
        loseLife();
    }
}

void Mario::increaseCoins() {   // increase coin by one and checks if the number of coins is 20
    coins++; 
    if (coins == 20) {  // if number of coins is 20, increase lives by 1 and reset the numbers of coins
        curLives++;
        coins = 0;
    }
} 

void Mario::loseLife() {    // decrease life by one, reset power to 0 and number of enemies to 0 if mario still have some lives left 
    curLives--;
    if (curLives >= 1) {
        power = 0;
        numOfEnemiesDefeated = 0;
    }
}

void Mario::setPosition(int newLevel, int newRow, int newCol) {
    curLevel = newLevel;
    row = newRow;
    col = newCol;
}

void Mario::defeatEnemies() {   // increase number of enemies defeated by 1 and check if mario defeated 7 enemies in this life, then increase lives by 1 andd reset number of enemies defeated
    numOfEnemiesDefeated++;
    if (numOfEnemiesDefeated == 7) {
        curLives++;
        numOfEnemiesDefeated = 0;
    }
}

void Mario::moveRandom(int gridSize, std::ofstream logFile) {
    int direction = rand() % 4;     // generate a number from 0 to 3

    switch (direction) {
        case 0: // mario moves up
            row = (row - 1 + gridSize) % gridSize; 
            logFile << "Mario will move UP.\n";
            break;
        
        case 1: // mario will move down
            row = (row + 1) % gridSize;
            logFile << "Mario will move DOWN.\n";
            break;
        
        case 2: // mario will move left 
            col = (col - 1 + gridSize) % gridSize;
            logFile << "Mario will move LEFT.\n";
            break; 
        
        case 3: // mario will move right 
            col = (col + 1) % gridSize;
            logFile << "Mario will move RIGHT.\n";
            break;

    }
}

// getters
int Mario::getCurLevel() {
    return curLevel;
}

int Mario::getRow() {
    return row;
}

int Mario::getCol() {
    return col;
}

int Mario::getPower() {
    return power;
}

int Mario::getCurLives() {
    return curLives;
}

int Mario::getCoins() {
    return coins;
}