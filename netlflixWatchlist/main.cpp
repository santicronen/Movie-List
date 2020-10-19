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
	printf("4. Print films.\n");
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

	current->next->next = NULL;
	}
}

void delete(FILM *head, int id){
	struct FILM *temp = *head, *prev;

	if(temp != NULL && temp->key == id){
		*head = temp->next;
		free(temp);
		return;
	}

	while(temp != NULL && temp->key != id){
		prev = temp;
		temp = temp->next;
	}

	if(temp == NULL){
		return;
	}

	prev->next = temp->next;
	free(temp);
}

void printList(FILM *head){
	struct FILM *current = head;
	
	while(current != NULL){
		printf("ID: %d\n", current->key);
		printf("Title: %s\n", current->name);
		printf("Type: %s\n", current->type);
		printf("-------------------------");
		menu();
	}
}
int main(){
	struct FILM *head = NULL;

	// initial node
	head = (FILM *) malloc(sizeof(FILM));
		if (head == NULL) {
		    return 1;
		}

	printf("No films created. Please add one.\n");
	printf("ID: ");
	scanf("%d", &head->key);

	printf("Title: ");
	scanf("%s", &head->name);

	printf("Type: ");
	scanf("%s", &head->type);

	int option = menu();
	switch(option){
		case 1: insert(head); break;
		case 2: 
			int id;
			printf("Which ID do you want to delete?: ");
			scanf("%d", &id);
			delete(head, &id);
		// case 3: modify
		case 4: printList(head); break;
			
    	default: printf("Insert a valid value.\n"); menu();
  }
	return 0;
}
