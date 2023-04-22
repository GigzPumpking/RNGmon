#include "character.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Character {
    uint16_t BST;
    uint8_t hp;
    uint8_t atk;
    uint8_t def;
    uint8_t spa;
    uint8_t spd;
    uint8_t spe;
    char* name;
    char* abi;
    char* habi;
    char* type1;
    char* type2; 
};

uint16_t statTotal(Character *c) {
    return ((uint16_t) (c->hp + c->atk + c->def + c->spa + c->spd + c->spe));
}

Character *c_create(char* name, uint16_t stat, FILE *abi, FILE *type) {
    //stat is the user provided BST. If no BST is provided, randomizes a BST from range 200 to 720.
    
    /*Two ways to approach this: 
          1. build the stats starting from HP all the way to SPE, where SPE is the leftover BST.
          2. randomize everything, then balance the entire spread.
    */ 

    Character *c = calloc(1, sizeof(Character)); 
    c->BST = (stat)? stat: (random() % 520 + 200);
    c->name = name;
    stat_selector(c);
    c->abi = set_abi(abi);
    while (true) {
        c->habi = set_abi(abi);
        if (c->habi != c->abi) {
            break;
        }
    }
    c->type1 = set_type(type);
    c->type2 = set_type(type);
    return c;
}

void stat_selector(Character *c) {
    //a stat is randomized from 1 to 255. All stats are randomized within this range until the stat total matches the Character's BST.
    //This method is honestly really disgusting to me to be honest, but it is the simplest. 
    //I will likely implement a better algorithm with a more straightforward time complexity in the future.

    while (statTotal(c) != c->BST) {
        c->hp = (random() % 254) + 1;
        
        c->atk = (random() % 254) + 1;
        
        c->def = (random() % 254) + 1;;
        
        c->spa = (random() % 254) + 1;;
        
        c->spd = (random() % 254) + 1;;

        c->spe = (random() % 254) + 1;;
    }
}

void c_delete(Character *c) {
    free(c->type1);
    c->type1 = NULL;
    free(c->type2);
    c->type2 = NULL;
    free(c->abi);
    c->abi = NULL;
    free(c->habi);
    c->habi = NULL;
    free(c);
    c = NULL;
}

char* c_name(Character *c) {
    return c->name;
}

uint8_t c_hp(Character *c) {
    return c->hp;
}

uint8_t c_atk(Character *c) {
    return c->atk;
}

uint8_t c_def(Character *c) {
    return c->def;
}

uint8_t c_spa(Character *c) {
    return c->spa;
}

uint8_t c_spd(Character *c) {
    return c->spd;
}

uint8_t c_spe(Character *c) {
    return c->spe;
}

uint16_t c_BST(Character *c) {
    return c->BST;
}

char* c_abi(Character *c) {
    return c->abi;
}

char* c_type1(Character *c) {
    return c->type1;
}

char* c_type2(Character *c) {
    return c->type2;
}

char* set_abi(FILE *abi) {
    /*
    Reads the preset abilities.txt file. Chooses a random ability by selecting a random line from 0 to 297 (as there are 298 total current abilities)
    At the moment, currently assumes that an ability has a maximum character limit of 20 (including whitespace). 
    Considering the option of finding the largest line in abilities.txt and using its character count as the values for memory allocation and characters to read in fgets()
    */

    if (abi == NULL) {
        perror("Abilities file failed to open!");
        return NULL;
    }
    int rand = random() % 298; 
    char *a = (char *) calloc(20, sizeof(char));
    for (int i = 0; i < rand; i++) {
        if (fgets(a, 20, abi) == NULL) {
            break;
        }
    }
    a[strcspn(a, "\n")] = 0;
    //Above strcspn line courtesy to Tim Čas on StackOverflow (Removing trailing newline character from fgets)

    return a;
}

char* set_type(FILE *type) {
    /*
    Reads the preset types.txt file. Chooses a random type by selecting a random line from 0 to 17 (as there are 18 total current abilities)
    At the moment, currently assumes that a type has a maximum character limit of 20 (including whitespace). 
    */

    if (type == NULL) {
        perror("Type Chart file failed to open!");
        return NULL;
    }
    int rand = random() % 18;
    char *t = (char *) calloc(20, sizeof(char)); 
    for (int i = 0; i < rand; i++) {
        if (fgets(t, 20, type) == NULL) {
            break;
        }
    }
    t[strcspn(t, "\n")] = 0;
    //Above strcspn line courtesy to Tim Čas on StackOverflow (Removing trailing newline character from fgets)

    return t;
}

void c_print(Character *c, FILE *outfile) {
    fprintf(outfile, "Name: %s\n", c->name);
    fprintf(outfile, "HP: %" PRIu8 "\n", c->hp);
    fprintf(outfile, "ATK: %" PRIu8 "\n", c->atk);
    fprintf(outfile, "DEF: %" PRIu8 "\n", c->def);
    fprintf(outfile, "SPA: %" PRIu8 "\n", c->spa);
    fprintf(outfile, "SPD: %" PRIu8 "\n", c->spd);
    fprintf(outfile, "SPE: %" PRIu8 "\n", c->spe);
    fprintf(outfile, "BST: %" PRIu16 "\n", c->BST);
    fprintf(outfile, "Ability: %s\n", c->abi);
    fprintf(outfile, "Hidden Ability: %s\n", c->habi);
    if (c->type1 == c->type2) {
        fprintf(outfile, "Typing: %s\n", c->type1);
    }
    else {
        fprintf(outfile, "Typing: %s / %s\n", c->type1, c->type2);
    }
}
