/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#ifndef GAME_H
#define GAME_H
#include <string>

class Game {
    public: 
        Game();    // constructor 
        Game(int gridN, int numOfLevels, int initialLives, int coins, int nothing, int goombas, int koopas, int mush);  // overload constructor 
        ~Game();   // destructor 

        // getters 
        int getGridSize();  // grid size: N x N
        int getNumOfLevel();
        int getInitialLives();
        int getCoinsPerc(); // percentage of coin in grid 
        int getNothingPerc();
        int getGoombasPerc();
        int getKoopasPerc();
        int getMushPerc();
        
    private:
        int gridN; 
        int numOfLevels; 
        int lives;
        int coinsPerc;
        int nothingPerc;
        int goombasPerc;
        int koopasPerc;
        int mushPerc;

};

#endif