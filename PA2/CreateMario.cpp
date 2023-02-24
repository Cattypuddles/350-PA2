//
// Created by Vic on 2/23/2023.
//

#include <iostream>
#include "CreateMario.h"
#include "Enemies.h"

int marioMove;
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
    //place mario
}

void CreateMario :: marioMoves(){
   //probability for move
   marioMove = rand() % 4;

   switch (marioMove){
       case 0:
           checkLocation();
           //move up
           std::cout << "Mario moves up." << std::endl;
       case 1:
           checkLocation();
           //move right
           std::cout << "Mario moves right." << std::endl;
       case 2:
           checkLocation();
           //move down
           std::cout << "Mario moves down." << std::endl;
       case 3:
           checkLocation();
           //move left
           std::cout << "Mario moves left." << std::endl;
   }

   marioInteracts();
   statCheck();
}

void CreateMario :: marioInteracts(){
    // FIXME: Char c is invalid input but Im lazy rn
    switch (char c) {
        case 'M':
            powerLevel += 1;
            std::cout << "Mario has found a mushroom! He gains a Power Level!" << std::endl;
            marioMoves();
        case 'C':
            coinsCollected += 1;
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

void CreateMario :: statCheck(){
    if (coinsCollected == 20) {
        marioLives += 1;
        std::cout << "Mario has collected 20 coins. He gets an extra life!" << std::endl;
    }

    if (enemiesDefeated == 7) {
        marioLives += 1;
        std::cout << "Mario has defeated 7 enemies this life. He gets an extra life!" << std::endl;
    }
}

void CreateMario :: checkLocation(){
    //check mario location
    //check to see if going off map, if so, course correct
}

void marioFights(char c){
    bool hasWon;

    hasWon = enemyFight(char c);

    if (!hasWon){
        powerLevel -= 1;
        // FIXME: Check how dying works. If it's when PL = -1, then add a function for this.
    }
    else{
        enemiesDefeated += 1;
    }


}

