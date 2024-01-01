//
// Created by cedi2 on 30.12.2023.
//

#ifndef ENGINE_DATABASE_H
#define ENGINE_DATABASE_H

void absatz(int i){
    for(int j = 0; j < i; j++){
        printf("\n");
    }
}
void line(int i){
    printf("[");
    for (int j = 0; j < i; j++){
        printf("#");
    }
    printf("]\n");
}



#endif //ENGINE_DATABASE_H
