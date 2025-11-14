//
// Created by Vojtěch Kycelt on 14.11.2025.
//

#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "enemy.h"

class enemy_manager_c {



    public:
        enemy_manager_c();
        ~enemy_manager_c();

    void init();
    void update();
    void draw();

    void spawn_enemy();
    void spawn_wave();

};



#endif //ENEMY_MANAGER_H
