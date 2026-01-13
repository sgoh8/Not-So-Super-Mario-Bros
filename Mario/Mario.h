/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#ifndef MARIO_H
#define MARIO_H

#include <fstream>

class Mario {
    public:
        Mario(int startRow, int startCol, int initialLives);    // constructor
        ~Mario();       // destructor

        // getters
        int getCurLevel();
        int getRow();
        int getCol();
        int getPower();
        int getCurLives();
        int getCoins();

        // setters 
        void increasePower();
        void decreasePower();
        void increaseCoins();
        void loseLife();
        void setPosition(int newLevel, int newRow, int newCol);
        void defeatEnemies();
        void moveRandom(int gridSize, std::ofstream logFile);

    private:
        int curLevel;
        int row;
        int col;
        int curLives;
        int coins;
        int power;
        int numOfEnemiesDefeated;


};

#endif