// header file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

struct FILM{ //
    int key;
    char name[50];
    char type[50];

    struct FILM *next;
};

int menu();
void insert(FILM *head);
void printList(FILM *head);
void delete(FILM *head, int id);