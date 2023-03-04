//
// Created by Vic on 2/25/2023.
//

#include <iostream>
#include "Levels.h"

using namespace std;

int marioRow;
int marioColumn;
int currentLevel;
int coinPercent;
int emptyPercent;
int goombaPercent;
int koopaPercent;
int mushroomPercent;
int randomNum;
int lvlDimension;
int numOfLevels;
char*** marioWorld;

Levels:: Levels(){

//    //Create marioWorld 3D Array
//    marioWorld = new char**[numOfLevels];
//
//    for (int i = 0; i < numOfLevels; i++){
//
//        marioWorld[i] = new char*[lvlDimension];
//
//        for (int j=0; j < numOfLevels; j++){
//
//            marioWorld[i][j] = new char[lvlDimension];
//        }
//    }
//
//// Populate levels for the numberOfLevels
//    for (int i = 0; i < lvlDimension; i++){
//        for (int j=0; j < lvlDimension; j++){
//            marioWorld[i][j] = new char[itemAtSlot()];
//        }
//    }
//
//
//    //Randomly places Warp Pipe in Levels
//    for (int i = numOfLevels; i > 0; i--) {
//        int col = uniqueNumChosen();
//        int row = uniqueNumChosen();
//        marioWorld[i][row][col] = 'w';
//    }
//
//    //Randomly places Boss in Levels
//    for (int i = numOfLevels; i > 0; i--) {
//        int col = uniqueNumChosen();
//        int row = uniqueNumChosen();
//        if (marioWorld[i][row][col] != 'w'){
//            marioWorld[i][row][col] = 'b';
//        }
//    }
//
//    std::cout << "Mario World created." << std::endl;

}

Levels:: Levels(int num, int lvl){

    //Create marioWorld 3D Array
    marioWorld = new char**[num];

    for (int i = 0; i < num; i++){

        marioWorld[i] = new char*[lvl];

        for (int j=0; j < num; j++){

            marioWorld[i][j] = new char[lvl];
        }
    }

// Populate levels for the numberOfLevels
    for (int i = 0; i < lvl; i++){
        for (int j=0; j < lvl; j++){
            marioWorld[i][j] = new char[itemAtSlot()];
        }
    }


    //Randomly places Warp Pipe in Levels
    for (int i = num; i > 0; i--) {
        int col = uniqueNumChosen();
        int row = uniqueNumChosen();
        marioWorld[i][row][col] = 'w';
    }

    //Randomly places Boss in Levels
    for (int i = num; i > 0; i--) {
        int col = uniqueNumChosen();
        int row = uniqueNumChosen();
        if (marioWorld[i][row][col] != 'w'){
            marioWorld[i][row][col] = 'b';
        }
    }

    std::cout << "Mario World 2 created." << std::endl;

}

Levels::~Levels(){

}

int Levels::getCurrentLevel() {
    return currentLevel;
}

int Levels::getMarioRow() {
    return marioRow;
}

int Levels::getMarioColumn() {
    return marioColumn;
}

void Levels::printLevel() {

}

void Levels::clearCurrentMarioLocation(){
    //set the current level's grid value at marioRow / marioColumn to "x"
}

void Levels::goToNextLevel(){
    currentLevel++;
}

void Levels::placeMarioInLevel() {
    marioRow = uniqueNumChosen();
    marioColumn = uniqueNumChosen();
    // pick row number between 0 and (levelDimension - 1)
    // ex: levelDimension is 5, pick a number between 0 and 4
    // pick column number between 0 and (levelDimension - 1)
    // ex: levelDimension is 5, pick a number between 0 and 4
    // set marioRow to the random row number
    // set marioColumn to the random column number
}

bool Levels::isGameRunning(){
    if (currentLevel < numOfLevels) {
        return true;
    }
    return false;
}


char Levels::move(int direction){
// Return item at Mario's new position
char c;
switch (direction) {
    case 0:
        //up
        marioRow--;
        if (marioRow < 0){
            marioRow = lvlDimension;
        }

    case 1:
        // down
        marioRow++;
        if (marioRow > lvlDimension){
            marioRow = 0;
        }

    case 2:
        // left
        marioColumn--;
        if (marioColumn < 0){
            marioColumn = lvlDimension;
        }

    case 3:
        // right
        marioColumn++;
        if (marioColumn < lvlDimension){
            marioColumn = 0;
        }
    }

    c = marioWorld[currentLevel][marioRow][marioColumn];
    return c;
}

// check to see what item (if any) is in the same spot as mario
// call GetItemAtRow(marioRow, marioColumn)
// return the item char at mario's location
char Levels::getItemAtRow(int rowNumber, int columnNumber) {
    return marioWorld[currentLevel][marioRow][marioColumn];
}


void Levels::makeLevels(int levelDimension, int numberOfLevels, int baseCoinPercent,
                    int baseEmptyPercent, int baseGoombaPercent, int baseKoopaPercent, int baseMushroomPercent) {

    currentLevel = -1; //(one less than starting level because we'll call GoToNextLevel() )
    lvlDimension = levelDimension;
    numOfLevels = numberOfLevels;

    //assigns base coin percentages
    coinPercent = baseCoinPercent;
    emptyPercent = coinPercent + baseEmptyPercent;
    goombaPercent = emptyPercent + baseGoombaPercent;
    koopaPercent = goombaPercent + baseKoopaPercent;
    mushroomPercent = koopaPercent + baseMushroomPercent;


    std::cout << "Levels created." << std::endl;
}

char Levels::itemAtSlot(){
    int slotNum = rand() % 99;
    if (slotNum < coinPercent){
        return 'c';
    }
    else if (slotNum < emptyPercent){
        return 'x';
    }
    else if (slotNum < goombaPercent){
        return 'g';
    }
    else if (slotNum < koopaPercent){
        return 'k';
    }
    else{
        return 'm';
    }
}

int Levels::uniqueNumChosen(){
    randomNum = rand() % (lvlDimension-1);
    return randomNum;

}