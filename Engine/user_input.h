//
// Created by cedi2 on 01.01.2024.
//

#ifndef ENGINE_USER_INPUT_H
#define ENGINE_USER_INPUT_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int input(int amount){
    int input;
    do {
        printf("Bitte geben Sie die Zahl entsprechend des gewuenschten Spiels ein: ");
        scanf("%d", &input);
    } while (input < 1 || input > amount);
    return input;
}

#endif //ENGINE_USER_INPUT_H
