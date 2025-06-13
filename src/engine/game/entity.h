#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils.h"

typedef int ID;

typedef struct {
    unsigned int id;
    float x, y, z;
}Entity;

typedef struct {
    Entity self;

    char *name;
    int health;
    char *skin_color;
    float speed;
}Player;

typedef struct {
    Entity self;

    int health;
    int attack_damage;
}Monster;
