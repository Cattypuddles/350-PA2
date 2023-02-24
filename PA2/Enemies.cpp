//
// Created by Vic on 2/23/2023.
//

#include "Enemies.h"

bool win;

Enemies :: ~Enemies(){

}

bool Enemies :: enemyFight(char c){
    // FIXME: Char c is invalid input but Im lazy rn
    switch (char c){
        case 'K':
            //koopa fight
            if (win){
                return true;
            }
        case 'G':
            //koopa fight
            if (win){
                return true;
            }
        case 'B':
            //koopa fight
            if (win){
                return true;
            }
        default:
            return false;
    }
}

bool Enemies :: koopaFight(){

    //koopa - 65% chance to win

    return win;
};

bool Enemies :: goombaFight(){

    //goomba - 80% chance to win

    return win;
};

bool Enemies :: bossFight(){

    //boss - 50% chance to win??
    //FIXME: check boss chance win percentage

    return win;
};

