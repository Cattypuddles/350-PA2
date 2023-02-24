//
// Created by Vic on 2/23/2023.
//

#ifndef PA2_ENEMIES_H
#define PA2_ENEMIES_H


class Enemies {
public:

    bool win;

    ~Enemies();
    bool enemyFight(char c);
    bool koopaFight();
    bool goombaFight();
    bool bossFight();
};


#endif //PA2_ENEMIES_H
