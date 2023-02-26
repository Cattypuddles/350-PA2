//
// Created by Vic on 2/25/2023.
//
#include <string>
#include <iostream>

#include "Mario.h"

int marioLives;
int marioCoins;
int marioPowerLevel;
int marioPreviousPowerLevel;
int EnemiesDefeatedOnCurrentLife;
std::string lastAction;
std::string NextDirection;


SetLives(int initialNumberOfLives) {
   // Lives = initialNumberOfLives
}

int GetPreviousPowerLevel(){

}

std::string GetLastAction(){
    return lastAction;
}

int GetLivesRemaining(){
    return marioLives;
}

int GetNumberOfCoins(){

}

int GetNextDirection(){

}

Initialize(){
//nextDirection = random int between 1 and 4
//coins = 0 etc
}

Move(){
PreviousPowerLevel = PowerLevel
char result = Levels.Move(nextDirection)

bool haveLost = false

switch (result):
case "x":
// nothing
lastAction = "The position is empty"
case "m":
// EatMushroom()
lastAction = "Mario ate a mushroom"
case "c":
// PickupCoin()
lastAction = "Mario ate a mushroom"
case "k":
// haveLost = FightKoopa()
lastAction = "Mario ate a mushroom"
case "g":
// haveLost = FightGoomba()
if (haveLost)
lastAction = "Mario fought a Goomba and lost"
else
lastAction = "Mario fought a Goomba and lost"
case "b":
// haveLost = FightBoss()
lastAction = "Mario ate a mushroom"
case "w":
// Warp()
lastAction = "Mario ate a mushroom"

if (haveLost)
Move()
else
Levels.ClearCurrentMarioLocation()

nextDirection = random int between 1 and 4
}

void Warp() {
    Levels.GoToNextLevel()
}


bool FightBoss(){
haveLost = false
pick a number between 0 and 99
if the number is less than 50
// we won
DefeatBoss()
else
// we lost
haveLost = true
LoseToBoss()
return haveLost
}
LoseToBoss(){
PowerLevel = PowerLevel - 2
if (PowerLevel < 0)
Lives--
PowerLevel = 0
}
DefeatBoss(){
EnemiesDefeatedOnCurrentLife++
if (EnemiesDefeatedOnCurrentLife == 7)
Lives++
EnemiesDefeatedOnCurrentLife = 0
Warp()
}
bool FightKoopa(){
haveLost = false
pick a number between 0 and 99
if the number is less than 65
// we won
DefeatEnemy()
else
// we lost
haveLost = true
LoseToEnemy()
return haveLost
}
LoseToEnemy(){
PowerLevel--
if (PowerLevel < 0)
Lives--
PowerLevel = 0
}
DefeatEnemy(){
EnemiesDefeatedOnCurrentLife++
if (EnemiesDefeatedOnCurrentLife == 7)
Lives++
EnemiesDefeatedOnCurrentLife = 0
}
PickupCoin(){
Coins++  // aka Coins = Coins + 1
if (Coins > 20)
{
Coins = 0
Lives++
}
}

EatMushroom(){
PowerLevel = PowerLevel + 1
if (PowerLevel > 3)
PowerLevel = 3
}