#include <iostream>
#include <fstream>

#include "Mario.h"
#include "Levels.h"

int numberOfLevels;
int levelDimension;
int numberOfLives;
int baseCoinPercent;
int baseEmptyPercent;
int baseGoombasPercent;
int baseKoopasPercent;
int mushroomsPercent;



void LoadData(){

    std::ifstream inFile;

    inFile.open("Mario.txt");

    if (!inFile){
        std::cout << "Unable to open Mario file. Please check that file is in place and try again." << std::endl;
    }

    std::ifstream input_stream( "Mario.txt", std::ifstream::in );

    while (input_stream >> numberOfLevels >> levelDimension >> numberOfLives >> baseCoinPercent >> baseEmptyPercent >>
    baseGoombasPercent >> baseKoopasPercent >> mushroomsPercent) {
        std::cout << "Mario.txt Read successfully." << std::endl;
    }

    inFile.close();
}

int main() {
    LoadData();

    Levels *levels = new Levels(numberOfLevels, levelDimension);
    Mario *mario = new Mario();

    mario->initialize(numberOfLives);
    levels->makeLevels(levelDimension, numberOfLevels, baseCoinPercent, baseEmptyPercent, baseGoombasPercent,
                       baseKoopasPercent, mushroomsPercent);

    while (levels->isGameRunning()) {
        mario->marioMove();
        std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
        std::cout<< "Level: " << levels->currentLevel << ". Mario is at position: (" << levels->marioRow << "," << levels->marioColumn <<
                 ". Mario is at power level " << mario->getPreviousPowerLevel() << ". " << mario->getLastAction() << " Mario has "
                 << mario->getLivesRemaining() << " lives left. Mario has " << mario->getNumberOfCoins() << " coins. Mario will move " <<
                 mario->getNextDirection() << std::endl;
        std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
    }
    return 0;
}


//void PrintStatus(){
//// print all the stuffs using the getter methods
//    std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
//    std::cout<< "Level: " << levels->currentLevel << ". Mario is at position: (" << levels->marioRow << "," << levels->marioColumn <<
//             ". Mario is at power level " << mario->getPreviousPowerLevel() << ". " << mario->getLastAction() << " Mario has "
//             << mario->getLivesRemaining() << " lives left. Mario has " << mario->getNumberOfCoins() << " coins. Mario will move " <<
//             mario->getNextDirection() << std::endl;
//    std::cout << "☆☆☆☆☆☆☆☆☆☆" << std::endl;
//}




