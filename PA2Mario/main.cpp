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
std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
std::cout<< "Level: " << level->currentLevel << ". Mario is at position: (" << level->marioRow << "," << level->marioColumn <<
    ". Mario is at power level " << mario->GetPreviousPowerLevel() << ". " << mario->GetLastAction() << " Mario has "
    << mario->GetLivesRemaining() << " lives left. Mario has " << mario->GetNumberOfCoins() << " coins. Mario will move " <<
    mario->GetNextDirection() << std::endl;
std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
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



