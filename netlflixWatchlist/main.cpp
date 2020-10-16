/*
                     ______
                   <((((((\\\
                   /      . }\
                   ;--..--._|}  >> I'll be back.
(\                 '--/\--'  )
 \\                | '-'  :'|
  \\               . -==- .-|
   \\               \.__.'   \--._
   [\\          __.--|       //  _/'--.          NETFLIX WATCHLIST
   \ \\       .'-._ ('-----'/ __/      \         by:
    \ \\     /   __>|      | '--.       |        > Cronenberg Santiago
     \ \\   |   \   |     /    /       /         > Martino Lucio
      \ '\ /     \  |     |  _/       /          > Ramirez Facundo
       \  \       \ |     | /        /
        \  \      \        /
*/

#include "main.h"

void menu(FILM *head){

  int option, id;
  char name[N], type[N];

  printf("<---- NETFLIX WATCHLIST ---->\n");
  printf("Select an option below.\n");
  printf("1. Add a film.\n");
  printf("2. Delete a film.\n");
  printf("3. Modify a film.\n");
	printf("Selection? ");

  scanf("%d", &option);
  switch(option){
    case 1:
      printf("\nID: ");
      scanf("%d", &id);

      printf("\nTitle: ");
      scanf("%s", &name);

      printf("\nType: ");
      scanf("%s", &type);

      push(head, id, name, type);
   // case 2: // delete
   // case 3: // modify
    default: printf("Insert a valid value."); menu();
  }
}

void push(FILM *head, int id, char name[], char type[]) {
    FILM *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (FILM *) malloc(sizeof(FILM));
    current->next->id = id;
    current->next->name = name;
    current->next->type = type;
    current->next->next = NULL;
}


int main(){
  FILM *head = NULL;

  head = (FILM *) malloc(sizeof(FILM));
	if (head == NULL) {
	    return 1;
	}

  menu(head);
}