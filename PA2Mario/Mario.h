//
// Created by Vic on 2/25/2023.
//

#ifndef PA2MARIO_MARIO_H
#define PA2MARIO_MARIO_H


class Mario {
public:
    int marioLives;
    int marioCoins;
    int marioPowerLevel;
    int marioPreviousPowerLevel;
    int enemiesDefeatedOnCurrentLife;
    std::string lastAction;
    int nextDirection;

    Mario();
    ~Mario();
    void setLives(int initialNumberOfLives);
    int getPreviousPowerLevel();
    std::string getLastAction();
    int getLivesRemaining();
    int getNumberOfCoins();
    std::string getNextDirection();
    void initialize(int l);
    void warp();
    void loseToBoss();
    void defeatBoss();
    void loseToEnemy();
    void defeatEnemy();
    bool fightBoss();
    bool fightKoopa();
    bool fightGoomba();
    void pickupCoin();
    void eatMushroom();
    void marioMove();
};


#endif //PA2MARIO_MARIO_H
