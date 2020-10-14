// header file

#include <stdio.h>
#include <stdlib.h>

struct FILM{ //
    int id;
    char name[50];
    char type[50];

    struct FILM *next;
};

void menu();
void push(FILM *head, int val);