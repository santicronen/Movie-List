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
	printf("9. Exit.\n");
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
	fflush(stdin);
	scanf("%d", &current->next->key);

	printf("Title: ");
	fflush(stdin);
	scanf("%[^\n]", current->next->name);

	printf("Type: ");
	fflush(stdin);
	scanf("%[^\n]", current->next->name);

	current->next->next = NULL;

	int option;
	do{
		printf("Add new film? (1/2): ");
		fflush(stdin);
		scanf("%d", &option);
		switch(option){
			case 1: insert(head); break;
			case 2: break;
				}
		}while(option != 1 && option != 2);
	}
	return;
}

void deleteList(FILM **head, int id){
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
	printf("Film deleted correctly. Returning to menu...\n");
	return;
}

void modify(FILM *head, int id){
	int nodoBuscado = id;
	FILM *primero = head;
	FILM *actual = (FILM *) malloc(sizeof(FILM));
	actual = primero;
	int encontrado = 0;
	if(primero!=NULL){
		while(actual != NULL && encontrado != 1){
			
			if(actual->key == nodoBuscado){

			printf("\nNode founded.");

			printf("Title: ");
			fflush(stdin);
			scanf("%[^\n]", &head->name);

			printf("Type: ");
			fflush(stdin);
			scanf("%[^\n]", &head->type);
			printf("\n Movie modified with succces\n\n");
			encontrado = 1;
			}
				
			actual = actual->next;
			return;
		}
		if(encontrado == 0){
			printf("\n Movie wasn't found\n\n");
		}
	}else{
		printf("\n The watchlist hasn´t movies\n\n");
	}
}

void printList(FILM *head){
	struct FILM *current = head;
	
	if(current == NULL){
		printf("Empty list.");
		return;
	}
	do{
		printf("-------------------------\n");
		printf("ID: %d", current->key);
		printf("\nTitle: %s", current->name);
		printf("\nType: %s\n", current->type);
		current = current->next;
	}while(current != NULL);
	return;
}

int main(){
	struct FILM *head = NULL;

	// initial node
	head = (FILM *) malloc(sizeof(FILM));
		if (head == NULL) {
		    return 1;
		}

	printf("<---- NETFLIX WATCHLIST ---->\n");
	printf("No films created. Please add one.\n");
	printf("ID: ");
	scanf("%d", &head->key);

	printf("Title: ");
	fflush(stdin);
	fgets(head->name, 50, stdin);

	printf("Type: ");
	fflush(stdin);
	fgets(head->type, 50, stdin);

		int control = 0;
	do{
		int option = menu();
		switch(option){
			case 1: insert(head); break;
			case 2: 
				int id;
				printf("Which ID do you want to delete?: ");
				scanf("%d", &id);
				deleteList(&head, id);
				break;
			case 3: 
				printf("Which ID do you want to modify?: ");
				scanf("%d", &id);
				modify(head, id);
				break;
			case 4: printList(head); break; 
			case 9: control = 1; break;
			default: printf("Insert a valid value.\n");
	}
  }while(control == 0);
	return 0;
}