//
// Created by Vic on 2/23/2023.
//

#include <iostream>
#include "CreateMario.h"

int marioLives;
int powerLevel;
int coinsCollected;
int enemiesDefeated;

// set power level to 0
//power level connects to life. If die, back to power level 0

CreateMario :: ~CreateMario(){

}

void CreateMario:: createMario(int lives){
    marioLives = lives;
    powerLevel = 0;
    coinsCollected = 0;
    enemiesDefeated = 0;
}

void CreateMario :: statCheck(){
    if (coinsCollected == 20) {
        marioLives = +1;
        std::cout << "Mario has collected 20 coins. He gets an extra life!" << std::endl;
    }

    if (enemiesDefeated == 7) {
        marioLives = +1;
        std::cout << "Mario has defeated 7 enemies this life. He gets an extra life!" << std::endl;
    }
}

void CreateMario :: marioMoves(){
   //probability for move
    //check to see if going off map, if so, course correct

   marioInteracts();
   statCheck();
}

void CreateMario :: marioInteracts(){
    switch (char c) {
        case 'M':
            powerLevel =+ 1;
            std::cout << "Mario has found a mushroom! He gains a Power Level!" << std::endl;
            marioMoves();
        case 'C':
            coinsCollected =+ 1;
            std::cout << "Mario has found a coin! He now has " << coinsCollected << " coins!" << std::endl;
            marioMoves();
        case 'K':
            //enemy script
        case 'G':
            //enemy script
        case 'B':
            //boss script
        case 'P':
            //level complete
            std::cout << "Mario has found a warp pipe! He advances to the next level. " << std::endl;
    }
}



