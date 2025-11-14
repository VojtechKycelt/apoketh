#pragma once

#include "enemy.h"

class enemy_manager_c {

    std::vector<enemy_c>				enemies;
    sf::Clock							clock;


    public:
        enemy_manager_c();
        ~enemy_manager_c();

        void                            init();
        void                            update();
        void                            draw();
        void                            spawn_enemy();
        void                            spawn_wave();

};

