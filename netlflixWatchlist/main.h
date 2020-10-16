// header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 60

struct FILM{ //
    int id;
    char name[N];
    char type[N];

    struct FILM *next;
};

void menu();
void push(FILM *head, int id, char name[], char type[]);