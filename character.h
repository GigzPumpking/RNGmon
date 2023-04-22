#pragma once

#include <string.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stdio.h>

typedef struct Character Character;

Character *c_create(char* name, uint16_t stat, FILE *abi, FILE *type);

void stat_selector(Character *c);

void c_delete(Character *c);

char* c_name(Character *c);

uint8_t c_hp(Character *c);

uint8_t c_atk(Character *c);

uint8_t c_def(Character *c);

uint8_t c_spa(Character *c);

uint8_t c_spd(Character *c);

uint8_t c_spe(Character *c);

uint16_t c_BST(Character *c);

char* c_abi(Character *c);

char* c_type1(Character *c);

char* c_type2(Character *c);

char* set_abi(FILE *abi);

char* set_type(FILE *type);

void c_print(Character *c, FILE *outfile);
