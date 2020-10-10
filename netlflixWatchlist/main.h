#include <stdio.h>

struct FILM{ //
    int id;
    char name[50];
    char type[50];

    struct FILM *next;
}