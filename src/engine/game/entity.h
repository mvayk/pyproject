#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../utils.h"

typedef int ID;

typedef struct {
    unsigned int id;
    int x, y, z;
}Entity;

typedef struct {
    Entity self;

    char *name;
    int health;
    char *skin_color;
}Player;

typedef struct {
    Entity self;

    int health;
    int attack_damage;
    
    int damage(int amount, ID entity) {
        health = health - amount;
    }
}Monster;
