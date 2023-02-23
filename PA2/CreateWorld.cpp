//
// Created by Vic on 2/23/2023.
//
#include <iostream>
#include "CreateWorld.h"
#include "CreateLevel.h"

bool isComplete;

CreateWorld :: ~CreateWorld(){

}

void CreateWorld :: createWorld(int levels, int size){
    //creates 3D array
    char*** marioWorld = new char**[levels];

    for (int i = 0; i < levels; i++){

        marioWorld[i] = new char*[size];

        for (int j=0; j < levels; i++){

            marioWorld[i][j] = new char[size];
        }
    }
    std::cout << "Mario World Created!" << std::endl;
    startGame();
}

//number of levels

//transition from levels
void CreateWorld :: levelTransition(){
    //call create level from level class
};

//instantiate create level
    //array of level # and size

void CreateWorld :: startGame() {

    //populate level
    //instantiate mario

}


