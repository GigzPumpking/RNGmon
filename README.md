By Hung Nguyen

# RNGMon

## Description:
Generate a completely random Pokemon with random stats, abilities, and typing. Has the potential for custom abilities and typings, given that the user specifies their own file for reading such data. This project was inspired by Donyell Marshall Jr's Your Pokemon Stat Generator at https://en.shindanmaker.com/1024594.

## Notes:
The random seed is based on the time. If you spam the command too quickly, you may receive the same output.

## Included Files:
        main.c
            - C program which parses through command line options, generating a new character (Pokemon) using inputted (or not) data. 

        character.c
            - C program which implements the Character ADT and the algorithm for generating one with random stats.

        character.h
            - Header file specifying the interface for character.c.

        abilities.txt
            - File containing all 298 known Pokemon abilities.

        types.txt
            - File containing all 18 known Pokemon types.

        Makefile
            - Used to build the main executable, clang-format relevant files, and clean the directory.

        README.md
            - Describes the program and its included program, including how to run and build and clean the directory.
 

## Build:
Run '$ make' on the command line within the directory to create the executable main file along with the relevant object files.

## Clean:
Run ‘$ make clean’ on the command line within the directory to remove the executable main file and any .o file in the directory.

## Run:
main: Run '$ ./main' along with any of the listed options:

        -o {file}            | - Specifies file to place generated data (default: stdout).

        -n {str}             | - Specifies name for the generated Pokemon (default: RNGMon). Use quotations ("") for multi-worded names.

        -b {num}             | - Specifies BST for the generated Pokemon (default: random num in range (200 - 720)).

        -a {file}            | - Specifies file to read potential abilities from (default: "abilities.txt").

        -t {file}            | - Specifies file to read potential types from (default: "types.txt").
