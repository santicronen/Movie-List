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

int menu(){

	printf("<---- NETFLIX WATCHLIST ---->\n");
  	printf("Select an option below.\n");
  	printf("1. Add a film.\n");
  	printf("2. Delete a film.\n");
	printf("3. Modify a film.\n");
	printf("Selection? ");

	int option;
  	scanf("%d", &option);
	
	return option;
}

void insert(FILM *head){
	struct FILM *current = head;
    while (current->next != NULL) {
        current = current->next;

	current->next = (FILM *) malloc(sizeof(FILM));

	printf("ID: ");
	scanf("%d", &current->next->key);

	printf("Title: ");
	scanf("%s", &current->next->name);

	printf("Type: ");
	scanf("%s", &current->next->type);

	// current->next->next = NULL;
	}
}

int main(){
	struct FILM *head = NULL;

	head = (FILM *) malloc(sizeof(FILM));
		if (head == NULL) {
		    return 1;
		}

	int option = menu();
	switch(option){
		case 1:
			insert(head); break;
    	default: printf("Insert a valid value.\n"); menu();
  }
}