//
// Created by Vic on 2/23/2023.
//

#ifndef PA2_CREATEMARIO_H
#define PA2_CREATEMARIO_H


class CreateMario {
public:
    int marioLives;
    int powerLevel;
    int coinsCollected;
    int enemiesDefeated;

    ~CreateMario();
    void createMario(int lives);
    void statCheck();
    void marioMoves();
    void marioInteracts();
    void checkLocation();
};


#endif //PA2_CREATEMARIO_H
