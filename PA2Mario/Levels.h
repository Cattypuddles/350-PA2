//
// Created by Vic on 2/25/2023.
//

#ifndef PA2MARIO_LEVELS_H
#define PA2MARIO_LEVELS_H


class Levels {
public:
    int marioRow;
    int marioColumn;
    int currentLevel;
    int coinPercent;
    int emptyPercent;
    int goombaPercent;
    int koopaPercent;
    int mushroomPercent;
    int randomNum;

    Levels();
    Levels(int num, int lvl);
    ~Levels();
    int getCurrentLevel();
    int getMarioRow();
    int getMarioColumn();
    void printLevel();
    void clearCurrentMarioLocation();
    void goToNextLevel();
    void placeMarioInLevel(); // not sure if this is supposed to be void
    bool isGameRunning();
    char getItemAtRow(int rowNumber, int columnNumber);
    void makeLevels(int levelDimension, int numberOfLevels, int baseCoinPercent,
                    int baseEmptyPercent, int baseGoombaPercent, int baseKoopaPercent, int baseMushroomPercent);
    char itemAtSlot();
    int uniqueNumChosen();
    char move(int direction);
};


#endif //PA2MARIO_LEVELS_H
