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
int EnemiesDefeatedOnCurrentLife;
std::string lastAction;
std::string nextDirection;


void SetLives(int initialNumberOfLives) {
   marioLives = initialNumberOfLives;
}

int GetPreviousPowerLevel(){
    return marioPreviousPowerLevel;
}

std::string GetLastAction(){
    return lastAction;
}

int GetLivesRemaining(){
    return marioLives;
}

int GetNumberOfCoins(){
    return marioCoins;
}

std::string GetNextDirection(){
    return nextDirection;
}

void Initialize(int l){
    int moveDirection = rand() % 4;
    //nextDirection = random int between 1 and 4
    marioCoins = 0;
    marioPowerLevel = 0;
    EnemiesDefeatedOnCurrentLife = 0;
    marioLives = int l;
}

void Warp() {
    Levels.GoToNextLevel();
}

void LoseToBoss(){
    marioPowerLevel = marioPowerLevel - 2;
    if (marioPowerLevel < 0) {
        marioLives--;
        marioPowerLevel = 0;
    }
}

void DefeatBoss(){
    EnemiesDefeatedOnCurrentLife++;
    if (EnemiesDefeatedOnCurrentLife == 7) {
        marioLives++;
        EnemiesDefeatedOnCurrentLife = 0;
    }
    Warp();
}

void LoseToEnemy(){
    marioPowerLevel--;
    if (marioPowerLevel < 0){
        marioLives--;
        marioPowerLevel = 0;
    }
}

void DefeatEnemy(){
    EnemiesDefeatedOnCurrentLife++;
    if (EnemiesDefeatedOnCurrentLife == 7) {
        marioLives++;
        EnemiesDefeatedOnCurrentLife = 0;
    }
}

bool FightBoss() {
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 50) {
        DefeatBoss();
    }
    else {
        // we lost
        haveLost = true;
        LoseToBoss();
    }
    return haveLost;
}

bool FightKoopa(){
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 65) {
        DefeatEnemy();
    }
    else {
        // we lost
        haveLost = true;
        LoseToEnemy();
    }
    return haveLost;
}

bool FightGoomba(){
    bool haveLost = false;
    int fightingHands = rand() % 99;
    if (fightingHands < 80) {
        DefeatEnemy();
    }
    else {
        // we lost
        haveLost = true;
        LoseToEnemy();
    }
    return haveLost;
}

void PickupCoin(){
    marioCoins++; // aka Coins = Coins + 1
    if (marioCoins > 20){
        marioCoins = 0;
        marioLives++;
    }
}

void EatMushroom(){
    marioPowerLevel = marioPowerLevel + 1;
    if (marioPowerLevel > 3) {
        marioPowerLevel = 3;
    }
}

void marioMove() {
    marioPreviousPowerLevel = marioPowerLevel;

    char result = Levels.Move(nextDirection);

    bool haveLost = false;

    switch (result) {
        case 'x':
            // nothing
            lastAction = "The position was empty.";
        case 'm':
            EatMushroom();
            lastAction = "Mario ate a mushroom.";
        case 'c':
            PickupCoin();
            lastAction = "Mario picked up a coin.";
        case 'k':
            haveLost = FightKoopa();
            if (haveLost)
                lastAction = "Mario fought a Koopa and lost.";
            else
                lastAction = "Mario fought a Koopa and won.";
        case 'g':
            haveLost = FightGoomba();
            if (haveLost)
                lastAction = "Mario fought a Goomba and lost.";
            else
                lastAction = "Mario fought a Goomba and won.";
        case 'b':
            haveLost = FightBoss();
            if (haveLost)
                lastAction = "Mario fought the boss and lost.";
            else
                lastAction = "Mario fought the boss and won.";
            Warp();
        case 'w':
            Warp();
            lastAction = "Mario found a warp pipe.";
    }

    if (haveLost) {
        marioMove();
    } else {
        Levels.ClearCurrentMarioLocation();

        nextDirection = rand() % 4;
    }
}