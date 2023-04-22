#include "character.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#define OPTIONS "n:b:o:a:t:"

/*
Known issues: 
    1. The program will rarely segfault due to an issue with the stat distributor.
       Note: The stat distributor algorithm is poor, so this will have to be redone anyway.
*/

int main(int argc, char **argv) { 
    uint32_t seed = time(0);
    srandom(seed);
    char *NAME = "RNGMon";
    uint16_t BST = 0; 
    FILE *outfile = stdout;
    FILE *abi = fopen("abilities.txt", "r");
    FILE *type = fopen("types.txt", "r");

    int opt = 0;
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'n': NAME = strdup(optarg); break;
        case 'b': BST = (uint16_t) strtoul(optarg, NULL, 10); break;
        case 'o': outfile = fopen(optarg, "w"); break;
        case 'a': abi = fopen(optarg, "r"); break;
        case 't': type = fopen(optarg, "r"); break;

        /*
        Note: Implement check for if file is proper after the fopen.
        */
        }
    }
 
    Character *HERO = c_create(NAME, BST, abi, type);
    c_print(HERO, outfile); 
    fclose(outfile);
    fclose(abi);
    fclose(type);
    return 0;
}
