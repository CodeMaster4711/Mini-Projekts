#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datenbank.h"
#include <unistd.h>


void print_ui(char *C, int size);
int random();
int game_engine();
void coin_counter();
int win_check(char *temp_array, int size);
void clear_console();
void animation();


int main() {
    srand(time(NULL));
    char i;
    printf("Druecken Sie die Eingabetaste, um die Funktion auszufuehren.\n");

    coin_counter();
    return 0;
}

void print_ui(char * C, int size){
    printf("[");
    for(int i = 0; i < size; i++){
        printf("%c", C[i]);
        if (i < size - 1) {printf("|");}
        else if(i == size - 1) {printf("");}

    }
    printf("]");
    printf("\n");
}


int random() {
    return rand() % 5;
}

int game_engine(){
    char C[] = {'H', 'X', 'O', 'E','L', 'N'};

    struct temp_sign one;
    struct temp_sign two;
    struct temp_sign three;
    struct temp_sign four;
    struct temp_sign five;

    one.position = random();
    one.sign = C[one.position];

    two.position = random();
    two.sign = C[two.position];

    three.position = random();
    three.sign = C[three.position];

    four.position = random();
    four.sign = C[four.position];

    five.position = random();
    five.sign = C[five.position];

    char temp[5] = {one.sign, two.sign, three.sign, four.sign, five.sign};
    char *temp_array = temp;
    int size = sizeof(temp)/sizeof(temp[0]);

    print_ui(temp_array, size);
    int J = win_check(temp_array, size);
    return J;
}

void coin_counter(){
    struct user user1;
    user1.coins = 5000;
    char i;
    printf("Sie haben %d Coins.\n", user1.coins);
    int k = 0;
    while ((i = getchar()) == '\n') {
        if(k == 1){
            clear_console();
        }
        user1.coins = user1.coins - 20;
        animation();
        int  J = game_engine();
        switch (J) {
            case 0:
                printf("Sie haben leider nichts gewonnen.\n");
                break;
            case 1:
                printf("Sie haben 50 Coins gewonnen.\n");
                user1.coins = user1.coins + 50;
                break;
            case 2:
                printf("Sie haben 400 Coins gewonnen.\n");
                user1.coins = user1.coins + 400;
                break;
            case 3:
                printf("Sie haben 5000 Coins gewonnen.\n");
                user1.coins = user1.coins + 5000;
                break;

        }
        if(user1.coins <= 0){
            printf("Sie haben keine Coins mehr.\n");
            break;
        }
        k = 1;
        printf("Sie haben %d Coins.\n", user1.coins);
    }
}

int win_check(char *temp_array, int size){
    int count = 1;
    int jackpot = 0;
    for(int i = 0; i < size - 1; i++){
        if(temp_array[i] == temp_array[i+1]){
            count++;
            if(count == 3){
                jackpot = 1;
            }
            if(count == 4){
                jackpot = 2;
            }
            if(count == 5){
                jackpot = 3;
            }
        } else {
            count = 1;
        }
    }
    return jackpot;
}

void clear_console() {
    system("cls");
}

void animation(){
    char *frames[] = {
            "[H|X|O|E|L]",
            "[X|O|E|L|N]",
            "[O|E|L|N|H]",
            "[E|L|N|H|X]",
            "[L|N|H|X|O]",
            "[N|H|X|O|E]",
    };
    int frames_length = sizeof(frames) / sizeof(frames[0]);

    for(int i = 0; i < 10; i++) {
        printf("\r%s", frames[i % frames_length]);
        fflush(stdout);
        usleep(200000); // Pause for 200 milliseconds
    }
    printf("\r"); // Clear the line

}

