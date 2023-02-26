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
    int EnemiesDefeatedOnCurrentLife;
    std::string lastAction;
    std::string nextDirection;

    void SetLives(int initialNumberOfLives);
    int GetPreviousPowerLevel();
    std::string GetLastAction();
    int GetLivesRemaining();
    int GetNumberOfCoins();
    std::string GetNextDirection();
    void Initialize(int l);
    void Warp();
    void LoseToBoss();
    void DefeatBoss();
    void LoseToEnemy();
    void DefeatEnemy();
    bool FightBoss();
    bool FightKoopa();
    bool FightGoomba();
    void PickupCoin();
    void EatMushroom();
    void marioMove();
};


#endif //PA2MARIO_MARIO_H
