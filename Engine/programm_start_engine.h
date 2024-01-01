//
// Created by cedi2 on 01.01.2024.
//

#ifndef ENGINE_PROGRAMM_START_ENGINE_H
#define ENGINE_PROGRAMM_START_ENGINE_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void start_engine(char path[260], char exe[260]){
        char command[300];
        sprintf(command, "cd /D %s && start %s", path, exe);
        system(command);

}

#endif //ENGINE_PROGRAMM_START_ENGINE_H
