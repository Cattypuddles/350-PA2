//
// Created by Vic on 2/25/2023.
//

#include "Levels.h"

int marioRow;
int marioColumn;
int currentLevel;

int GetCurrentLevel(){

}

int GetMarioRow(){

}

int GetMarioColumn(){

}

void PrintLevel(){

}


void ClearCurrentMarioLocation(){
//set the current level's grid value at marioRow / marioColumn to "x"
}

void GoToNextLevel(){
currentLevel++
PlaceMarioInLevel()
}

bool IsGameRunning(){
    if (currentLevel < the third dimension of the array){
        return true;
    }
return false;
}

char Move(int direction) {
    //Return item at Mario's new position


// switch (direction):

// case 1: // up
// subtract 1 from marioRow
// if marioRow < 0 then marioRow = levelDimension
// ex: if the level is 5x5 and mario tries to move off the level (less than 0),
//     set marioRow to 4

// case 2: // down
// add 1 to marioRow
// if marioRow > (levelDimension - 1), then marioRow = 0
// ex: if the level is 5x5 and mario tries to move off the level (more than 4),
//     set marioRow to 0

// case 3: // left
// subtract 1 from marioColumn
// if marioColumn < 0 then marioColumn = levelDimension
// ex: if the level is 5x5 and mario tries to move off the level (less than 0),
//     set marioColumn to 4

// case 4: // right
// add 1 to marioColumn
// if marioColumn > (levelDimension - 1), then marioColumn = 0
// ex: if the level is 5x5 and mario tries to move off the level (more than 4),
//     set marioColumn to 0

// check to see what item (if any) is in the same spot as mario
// call GetItemAtRow(marioRow, marioColumn)

// return the item char at mario's location
}

char GetItemAtRow(int rowNumber, int columnNumber){
//return whatever character is at the row/column for the current level
}


void PlaceMarioInLevel() {
// pick row number between 0 and (levelDimension - 1)
// ex: levelDimension is 5, pick a number between 0 and 4

// pick column number between 0 and (levelDimension - 1)
// ex: levelDimension is 5, pick a number between 0 and 4

// set marioRow to the random row number
// set marioColumn to the random column number
}


void MakeLevels(int levelDimension, int numberOfLevels, int baseCoinPercent,
                int baseEmptyPercent, int baseGoombaPercent, int baseKoopaPercent, int baseMushroomPercent){

currentLevel = -1 (one less than starting level because we'll call GoToNextLevel() )
// baseCoinPercent = 20
// baseEmptyPercent = 50
// baseGoombaPercent = 10
// baseKoopaPercent = 15
// baseMushroomPercent = 5

// coinPercent = baseCoinPercent                        // 20
// emptyPercent = coinPercent + baseEmptyPercent        // 70
// goombaPercent = emptyPercent + baseGoombaPercent     // 80
// koopaPercent = goombaPercent + baseKoopaPercent      // 95
// mushroomPercent = koopaPercent + baseMushroomPercent // 100

// create levels for the numberOfLevels
// ex: for i = 0; i < numberOfLevels; i++
// create an array of levelDimension by levelDimension
// so if levelDimension is 5, then it's a 5x5 array

marioWorld[i] = new char*[size];

for (int j=0; j < levels; i++){
marioWorld[i][j] = new char[size];
}

// for each slot in the 2D array:

// pick a randomNumber between 0 and 99
// if randomNumber < coinPercent
// coin
// if randomNumber < emptyPercent
// empty
// if randomNumber < goombaPercent
// goomba
// if randomNumber < koopaPercent
// koopa
// otherwise, mushroom

// assign warp pipe
// pick row number between 0 and (levelDimension - 1)
// ex: levelDimension is 5, pick a number between 0 and 4

// pick column number between 0 and (levelDimension - 1)
// ex: levelDimension is 5, pick a number between 0 and 4

// assign warpPipe to the column/row you picked
// assign boss
// same as warp pipe but for the boss
GoToNextLevel()
}