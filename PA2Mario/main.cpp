#include <iostream>

int main() {
    levels = new Levels();
    mario = new Mario();
    mario.Initialize();
    LoadData();

    while levels.IsGameRunning();
    mario.Move();
    PrintStatus();
    return 0;
}

void PrintStatus(){
// print all the stuffs using the getter methods
}


void LoadData(){
load in the text file and store the info:
int numberOfLevels
int levelDimension
int numberOfLives
int coinPercent
int emptyPercent
int goombasPercent
int koopasPercent
int mushroomsPercent
levels.MakeLevels(levelDimension, numberOfLevels, coinPercent, emptyPercent, goombasPercent,
        koopasPercent, mushroomsPercent)
mario.SetLives(numberOfLives)
}

