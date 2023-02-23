//
// Created by Vic on 2/23/2023.
//

#ifndef PA2_CREATEWORLD_H
#define PA2_CREATEWORLD_H


class CreateWorld {
public:
    bool isComplete;

    ~CreateWorld();
    void createWorld(int levels, int size);
    void levelTransition();
    void startGame();
};


#endif //PA2_CREATEWORLD_H
