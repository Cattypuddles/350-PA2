//
// Created by Vic on 2/25/2023.
//
#include <string>
#include <iostream>

#include "Mario.h"
#include "Levels.h"

int marioLives;
int marioCoins;
int marioPowerLevel;
int marioPreviousPowerLevel;
int enemiesDefeatedOnCurrentLife;
int nextDirection = 0;

std::string lastAction;
std::string textNextDirection;

Levels *levelss;


Mario::Mario(){

}

Mario::Mario(Levels *levelsInput){
    levelss = levelsInput;
}

Mario::~Mario(){

}

void Mario::setLives(int initialNumberOfLives) {
   marioLives = initialNumberOfLives;
}

int Mario::getPreviousPowerLevel(){
    return marioPreviousPowerLevel;
}

std::string Mario::getLastAction(){
    return lastAction;
}

int Mario::getLivesRemaining(){
    return marioLives;
}

int Mario::getNumberOfCoins(){
    return marioCoins;
}

std::string Mario::getNextDirection(){
    if (nextDirection == 0){
        textNextDirection = "Up";
    }
    if (nextDirection == 1){
        textNextDirection = "Down";
    }
    if (nextDirection == 2){
        textNextDirection = "Left";
    }
    if (nextDirection == 3){
        textNextDirection = "Right";
    }
    return textNextDirection;
}

void Mario::initialize(int l){
    int moveDirection = rand() % 4;
    //nextDirection = random int between 1 and 4
    marioCoins = 0;
    marioPowerLevel = 0;
    enemiesDefeatedOnCurrentLife = 0;
    marioLives = l;
    nextDirection = rand() % 4;
    levelss->placeMarioInLevel();
    std::cout << "Mario initialized" << std::endl;
}

void Mario::warp() {
    levelss->goToNextLevel();
}

void Mario::loseToBoss(){
    marioPowerLevel = marioPowerLevel - 2;
    if (marioPowerLevel < 0) {
        marioLives--;
        marioPowerLevel = 0;
    }
}

void Mario::defeatBoss(){
    enemiesDefeatedOnCurrentLife++;
    if (enemiesDefeatedOnCurrentLife == 7) {
        marioLives++;
        enemiesDefeatedOnCurrentLife = 0;
    }
    warp();
}

void Mario::loseToEnemy(){
    marioPowerLevel--;
    if (marioPowerLevel < 0){
        marioLives--;
        marioPowerLevel = 0;
    }
}

void Mario::defeatEnemy(){
    enemiesDefeatedOnCurrentLife++;
    if (enemiesDefeatedOnCurrentLife == 7) {
        marioLives++;
        enemiesDefeatedOnCurrentLife = 0;
    }
}

bool Mario::fightBoss() {
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 50) {
        defeatBoss();
    }
    else {
        // we lost
        haveLost = true;
        loseToBoss();
    }
    return haveLost;
}

bool Mario::fightKoopa(){
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 65) {
        defeatEnemy();
    }
    else {
        // we lost
        haveLost = true;
        loseToEnemy();
    }
    return haveLost;
}

bool Mario::fightGoomba(){
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 80) {
        defeatEnemy();
    }
    else {
        // we lost
        haveLost = true;
        loseToEnemy();
    }
    return haveLost;
}

void Mario::pickupCoin(){
    marioCoins++; // aka Coins = Coins + 1
    if (marioCoins > 20){
        marioCoins = 0;
        marioLives++;
    }
}

void Mario::eatMushroom(){
    marioPowerLevel = marioPowerLevel + 1;
    if (marioPowerLevel > 3) {
        marioPowerLevel = 3;
    }
}

void Mario::marioMove() {
    marioPreviousPowerLevel = marioPowerLevel;

    char result;
    result = levelss->move(nextDirection);

    bool haveLost = false;

    switch (result) {
        case 'x':
            // nothing
            lastAction = "The position was empty.";
            break;
        case 'm':
            eatMushroom();
            lastAction = "Mario ate a mushroom.";
            levelss->clearCurrentMarioLocation();
            break;
        case 'c':
            pickupCoin();
            lastAction = "Mario picked up a coin.";
            levelss->clearCurrentMarioLocation();
            break;
        case 'k':
            haveLost = fightKoopa();
            if (haveLost)
                lastAction = "Mario fought a Koopa and lost.";
            else {
                lastAction = "Mario fought a Koopa and won.";
                levelss->clearCurrentMarioLocation();
            }
            break;
        case 'g':
            haveLost = fightGoomba();
            if (haveLost)
                lastAction = "Mario fought a Goomba and lost.";
            else {
                lastAction = "Mario fought a Goomba and won.";
                levelss->clearCurrentMarioLocation();
            }
            break;
        case 'b':
            haveLost = fightBoss();
            if (haveLost)
                lastAction = "Mario fought the boss and lost.";
            else {
                lastAction = "Mario fought the boss and won.";
                warp();
            }
            break;
        case 'w':
            warp();
            lastAction = "Mario found a warp pipe.";
            break;
    }

    if (haveLost) {
        marioMove();
    }

    nextDirection = rand() % 4;
}