/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "Game.h" 
#include <iostream>
#include <fstream>

Game::Game() {    // initialise all variables to 0 
    gridN = 0;
    numOfLevels = 0;
    lives = 0;

    coinsPerc = 0;
    nothingPerc = 0;
    goombasPerc = 0;
    koopasPerc = 0;
    mushPerc = 0;

}

Game::Game(int n, int levels, int initialLives, int coins, int nothing, int goombas, int koopas, int mush) {
    gridN = n;
    numOfLevels = levels;
    lives = initialLives; 
    coinsPerc = coins;
    nothingPerc = nothing; 
    goombasPerc = goombas; 
    koopasPerc = koopas;
    mushPerc = mush;

    bool initialPerc = false;   // set the percentage check to false so it loops and ask until it adds up to 100

    while (initialPerc == false) {
        if (coinsPerc + nothingPerc + goombasPerc + koopasPerc + mushPerc == 100) {
            initialPerc = true;
        } else {
            initialPerc = false; 
            std::cout << "\n--------------------------------------";
            std::cout << "The inputted percentages of coins, nothing, goombas, koopas, and mushrooms does not add up to 100\nPlease try again" << std::endl;
            
            std::cout << "Percentage of coins: " << std:: endl;
            std::cin >> coinsPerc;

            std:: cout << "Percentage of nothing: " << std:: endl; 
            std::cin >> nothingPerc;

            std::cout << "Percentage of goombas: " << std::endl;
            std::cin >> goombasPerc;

            std::cout << "Percentage of koopas: " << std::endl;
            std::cin >> koopasPerc; 

            std::cout << "Percentage of mushrooms: " <<std::endl; 
            std::cin >> mushPerc;

        }
    }
    
    std::ofstream inFile("user_input.txt"); // creates an input file and stores the user input in it 
    if (inFile.is_open()) {
        inFile << numOfLevels << std::endl;
        inFile << gridN << std::endl;
        inFile << lives << std::endl;
        inFile << coinsPerc << std:: endl;
        inFile << nothingPerc << std::endl; 
        inFile << goombasPerc <<std::endl; 
        inFile << koopasPerc <<std::endl;
        inFile << mushPerc <<std::endl;

        inFile.close();
    }
}

Game::~Game() {}    // destructor

// getters
int Game::getGridSize() {
    return gridN;
}

int Game::getNumOfLevel() {
    return numOfLevels;
}

int Game::getInitialLives() {
    return lives;
}

int Game::getCoinsPerc() {
    return coinsPerc;
}

int Game::getGoombasPerc() {
    return goombasPerc;
}

int Game::getKoopasPerc() {
    return koopasPerc;
}

int Game::getMushPerc() {
    return mushPerc;
}