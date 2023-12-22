//
// Created by cedi2 on 21.12.2023.
//

#ifndef SPIEL_AUTOMAT_DATENBANK_H
#define SPIEL_AUTOMAT_DATENBANK_H


struct user {
    char name[20];
    int coins;
    int score;
};

struct random_col {
    int value;
};

struct sign {
    char sign;
};

struct temp_sign {
    char sign;
    int position;
};



#endif //SPIEL_AUTOMAT_DATENBANK_H
