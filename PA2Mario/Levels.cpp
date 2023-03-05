//
// Created by Vic on 2/25/2023.
//

#include <iostream>
#include "Levels.h"


//Member vars
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

//Constructors
Levels:: Levels(){

}

//Creates and Populates MarioWorld array
Levels:: Levels(int num, int lvl, int baseCoinPercent, int baseEmptyPercent, int baseGoombasPercent,
                int baseKoopasPercent, int mushroomsPercent){

    makeLevels(lvl, num, baseCoinPercent,
             baseEmptyPercent, baseGoombasPercent,  baseKoopasPercent,
               mushroomsPercent);

    //Create marioWorld 3D Array
    marioWorld = new char**[num]();

    for (int i = 0; i < num; i++){

        marioWorld[i] = new char*[lvl]();

        for (int j=0; j < lvl; j++){

            marioWorld[i][j] = new char[lvl]();

        }
    }

// Populate levels for the numberOfLevels
    for (int i = 0; i < num; i++){
        for (int j=0; j < lvl; j++){
            for (int f = 0; f < lvl; f++) {
                marioWorld[i][j][f] = itemAtSlot();
            }
        }
    }


    //Randomly places Warp Pipe in Levels
    for (int i = 0; i < num; i++) {
        int col = uniqueNumChosen();
        int row = uniqueNumChosen();
        marioWorld[i][row][col] = 'w';
    }

    //Randomly places Boss in Levels
    for (int i = 0; i < num; i++) {
        bool notPlaced = true;
        while (notPlaced) {
            int col = uniqueNumChosen();
            int row = uniqueNumChosen();
            if (marioWorld[i][row][col] != 'w') {
                marioWorld[i][row][col] = 'b';
                notPlaced = false;
            }
        }
    }

    std::cout << "Mario World 2 created." << std::endl;

    // print levels for the numberOfLevels
    for (int i = 0; i < num; i++){
        std::cout << "Level " << i << std::endl;
        for (int j=0; j < lvl; j++){
            for (int f = 0; f < lvl; f++) {
                std::cout << marioWorld[i][j][f];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

//Destructor
Levels::~Levels(){

}

//Getters for Print statement
int Levels::getCurrentLevel() {
    return currentLevel;
}

int Levels::getMarioRow() {
    return marioRow;
}

int Levels::getMarioColumn() {
    return marioColumn;
}

//Prints 2D array level
void Levels::printLevel() {
    for (int j=0; j < lvlDimension; j++){
        for (int f = 0; f < lvlDimension; f++) {
            if (j == marioRow && f == marioColumn) {
                std::cout << "H";
            }
            else {
                std::cout << marioWorld[currentLevel][j][f];
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

//Clears array location if Mario has picked up item or defeated enemy
void Levels::clearCurrentMarioLocation(){
    //set the current level's grid value at marioRow / marioColumn to "x
    marioWorld[currentLevel][marioRow][marioColumn] = 'x';
}

//Adds to currentLevel var
void Levels::goToNextLevel(){
    currentLevel++;
}

//Places Mario in the level
void Levels::placeMarioInLevel() {
    marioRow = uniqueNumChosen();
    marioColumn = uniqueNumChosen();
}

//Checks to see if Mario has completed the game
bool Levels::isGameRunning(){
    if (currentLevel < numOfLevels) {
        return true;
    }
    return false;
}

//Moves Mario in random location; Each has 25% probability
char Levels::move(int direction){
// Return item at Mario's new position
char c;
switch (direction) {
    case 0:
        //up
        marioRow--;
        if (marioRow < 0){
            marioRow = lvlDimension - 1;
        }
        break;

    case 1:
        // down
        marioRow++;
        if (marioRow > lvlDimension - 1){
            marioRow = 0;
        }
        break;
    case 2:
        // left
        marioColumn--;
        if (marioColumn < 0){
            marioColumn = lvlDimension - 1;
        }
        break;
    case 3:
        // right
        marioColumn++;
        if (marioColumn < lvlDimension - 1){
            marioColumn = 0;
        }
        break;
    case 9:
        placeMarioInLevel();
    }
    std::cout << "CurrentLevel = " << currentLevel << ", Row = " << marioRow << ", Column = " << marioColumn << std::endl;
    c = marioWorld[currentLevel][marioRow][marioColumn];
    return c;
}

//Gets item or enemy at array location
char Levels::getItemAtRow(int rowNumber, int columnNumber) {
    return marioWorld[currentLevel][marioRow][marioColumn];
}

//Initializes member vars from data read from file
void Levels::makeLevels(int levelDimension, int numberOfLevels, int baseCoinPercent,
                    int baseEmptyPercent, int baseGoombaPercent, int baseKoopaPercent, int baseMushroomPercent) {

    currentLevel = 0; //(one less than starting level because we'll call GoToNextLevel() )
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

//Determines which char to place on array spot based off of random num
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

//Makes a random num for new MarioColumn or MarioRow
int Levels::uniqueNumChosen(){
    randomNum = rand() % (lvlDimension-1);
    return randomNum;

}