/* 
Full name: San San Goh
Student ID: 2477595
Chapman email: sgoh@chapman.edu
Course number and section: CPSC 350-03
Assignment: PA2 - Not So Super Mario Bros
*/

#include "Level.h"
#include <cstdlib>
#include <string>

Level::Level(Game game, int gridN, bool warp) {
    size = gridN;

    grid = new char*[size]; // dynamic allocate 2d grid 
    for (int r = 0; r < size; r++) {
        grid[r] = new char[size];
    }

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            int randNum = rand() % 101; // generate a random number from 0 to 100 

            if (randNum < game.getCoinsPerc()) {    // put coin if it is from 0 to coin percent
                grid[r][c] = 'c';   

            } else if (randNum < (game.getCoinsPerc() + game.getNothingPerc())) {   // put nothing if it is in between coin percent and nothing percent
                grid[r][c] = 'x';   

            } else if (randNum < (game.getCoinsPerc() + game.getNothingPerc() + game.getGoombasPerc())) {   // put goomba if it is in bbetween nothing percent and goomba percent
                grid[r][c] = 'g';   

            } else if (randNum < (game.getCoinsPerc() + game.getNothingPerc() + game.getGoombasPerc() + game.getKoopasPerc())) {    // put koopa if it is in between goomba percent and koopa percent
                grid[r][c] = 'k';   

            } else {
                grid[r][c] = 'm';   // otherwise, put mushroom
            }
        }
    }

    // implement warp pipe 
    if (warp == false) {
        int warpRow = rand() % size; 
        int warpCol = rand() % size; 
        grid[warpRow][warpCol] = 'w';
    }

    // implement level boss 
    int bossRow = rand() % size;    // geenrate a random number for row and cell to put level boss in
    int bossCol = rand() % size; 
    grid[bossRow][bossCol] = 'b';

}

Level::~Level() {   // deletes grid when not needed to free memory 
    for (int r = 0; r < size; r++) {
        delete[] grid[r];
    }
    delete[] grid;

}

// getters
char Level::getTile(int r, int c) {
    return grid[r][c];
}

// setters
void Level::setTile(int r, int c, char object) {
    grid[r][c] = object;
}

void Level::interact(Mario mario, int level, std::ofstream logFile) {
    int r = mario.getRow();
    int c = mario.getCol();
    std::string action;

    logFile << "Level: " + mario.getCurLevel() << ". Mario is at position: (" << r << ", " << c << "). Mario is at power level " << mario.getPower() << ". ";

    switch (grid[r][c]) {
        case 'c':   // coin 
            mario.increaseCoins();
            action = "Mario collected a coin.";
            grid[r][c] = 'x';   // cell becomes nothing because coin was already collected
            break;
        
        case 'm':   // mushrooom 
            mario.increasePower();
            action = "Mario ate a mushroom.";
            grid[r][c] = 'x';
            break; 

        case 'g':   // goomba 
            if ((rand() % 101) >= 80) { //generate a number from 0 to 100 
                mario.defeatEnemies();
                action = "Mario encounrered a goomba and won."; 
                grid[r][c] = 'x';
        
            } else {
                mario.decreasePower();
                action = "Mario encountered a goomba and lost.";
            }
            break;
        
        case 'k':   // koopa    
            if ((rand() % 101) >= 65) {
                    mario.defeatEnemies();
                    action = "Mario encounrered a koopa and won."; 
                    grid[r][c] = 'x';
            
                } else {
                    mario.decreasePower();
                    action = "Mario encountered a koopa and lost.";

                }
            break;

        case 'b':   // level boss
            if ((rand() % 101) >= 50) {
                    mario.defeatEnemies();
                    action = "Mario encounrered a level boss and won."; 
                    grid[r][c] = 'x';
            
                } else {
                    mario.decreasePower();
                    mario.decreasePower();
                    action = "Mario encountered a level boss and lost.";

                }
            break;
        
        case 'w':   // warp pipe
            action = "Mario encountered a warp pipe and advanced to the next level.";
            mario.setPosition(level + 1, rand() % size, rand() % size);
            break;

        case 'x': // empty 
        default: 
            action = "Mario visted an empty space.";
            break;

    }
 
    logFile << "Mario has " << mario.getCurLives() << " left. Mario has " << mario.getCoins() << "coins.";

    mario.moveRandom(size, std::ofstream logFile);
}

void Level::print(Mario mario, int level) { // if mario is at the cell, print a 'H'
    std::cout << "==========";

    for (int r = 0; r < size; r++) { 
        for (int c = 0; c < size; c++) {
            if ((r == mario.getRow()) && (c == mario.getCol()) && (level == mario.getCurLevel())) {
                std::cout << 'H';

            } else {    // if mario is not at current cell, print the object at it 
                std::cout << grid[r][c];
            }
        }
        std::cout << "\n";  // new line for new row

    }
    std::cout << "==========";

}