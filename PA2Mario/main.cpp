#include <iostream>
#include <fstream>

#include "Mario.h"
#include "Levels.h"

int numberOfLevels;
int levelDimension;
int numberOfLives;
int coinPercent;
int emptyPercent;
int goombasPercent;
int koopasPercent;
int mushroomsPercent;


void PrintStatus(){
// print all the stuffs using the getter methods
}


void LoadData(){

    std::ifstream inFile;

    inFile.open("Mario.txt");

    if (!inFile){
        std::cout << "Unable to open Mario file. Please check that file is in place and try again." << std::endl;
    }

    std::ifstream input_stream( "Mario.txt", std::ifstream::in );

    while (input_stream >> numberOfLevels >> levelDimension >> numberOfLives >> coinPercent >> emptyPercent >>
    goombasPercent >> koopasPercent >> mushroomsPercent) {
        std::cout << "Mario.txt Read successfully." << std::endl;
    }

    inFile.close();
}

int main() {
    Levels *levels = new Levels();
    Mario *mario = new Mario();
    LoadData();
    mario->Initialize(numberOfLives);
    levels->MakeLevels(levelDimension, numberOfLevels, coinPercent, emptyPercent, goombasPercent,
                       koopasPercent, mushroomsPercent);

    while (levels->IsGameRunning()) {
        mario->marioMove();
        PrintStatus();
    }
    return 0;
}



