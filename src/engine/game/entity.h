#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils.h"

typedef unsigned int ID;

typedef struct {
    ID id;
    float height_clamp;
}Entity;

extern "C" {
    typedef struct {
        int fov; /* goes first because im too lazy to define in asm */

        Entity self;

        char *name;
        int health;
        char *skin_color;
        float speed;
    }Player;

    Player player;
}

typedef struct {
    Entity self;

    int health;
    int attack_damage;
}Monster;
