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

	printf("\n<---- NETFLIX WATCHLIST ---->\n");
  	printf("Select an option below.\n");
  	printf("	1. Add a film.\n");
  	printf("	2. Delete a film.\n");
	printf("	3. Modify a film.\n");
	printf("	4. Print films.\n");
	printf("	9. Exit.\n");
	printf(" Selection? ");

	int option;
  	scanf("%d", &option);
	
	return option;
}

void insert(FILM *head){
	struct FILM *current = head;
	
   	while (current->next != NULL) {
	    current = current->next;
	}
		current->next = (FILM *) malloc(sizeof(FILM));
		
		printf("\n Add film  \n");
		
		current->next->key= current->key +1;
	
		printf("	~Title: ");
		fflush(stdin);
		scanf("%[^\n]", current->next->name);
	
		printf("	~Type: ");
		fflush(stdin);
		scanf("%[^\n]", current->next->type);
	
		current->next->next = NULL;
	
		int option;
		do{
			printf("\n Add new film? [1: Yes | 2: No]: ");
			fflush(stdin);
			scanf("%d", &option);
			switch(option){
				case 1: insert(head); break;
				case 2: break;
					}
		}while(option != 1 && option != 2);
	
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
		printf("	Err - ID film not found...\n");
		return;
	}

	prev->next = temp->next;
	free(temp);
	printf("Film deleted correctly. Returning to menu...\n");
	return;
}

void modify(FILM *head, int id){
	
	int nodoBuscado = id;
	FILM *current = head;
	int encontrado = 0;
	
	if(current!= NULL){
	
		while(current != NULL && encontrado != 1){
			
			if(current->key == nodoBuscado){
							
				printf(" ~ Title - %s -  modify by :", current->name);
				fflush(stdin);
				scanf("%[^\n]", &current->name);
	
				printf(" ~ Type - %s -  modify by : ",current->type);
				fflush(stdin);
				scanf("%[^\n]", &current->type);
				printf("\n Movie modified with succces\n\n");
				encontrado = 1;
			}
				
			current = current->next;
		
		}
		if(encontrado == 0){
			printf("\n Movie wasn't found\n\n");
		}
	}else{
		printf("\n The watchlist hasn´t movies\n\n");
	}
	return;
}

void printList(FILM *head){
	struct FILM *current = head;
	
	if(current == NULL){
		printf("Empty list.");
		return;
	}
	do{
		printf("\n-------------------------\n");
		printf(" *ID: %d", current->key);
		printf("\n *Title: %s", current->name);
		printf("\n *Type: %s", current->type);
		current = current->next;
	}while(current != NULL);
	
	return;
}

int main(void){
	struct FILM *head = NULL;

	// initial node
	head = (FILM *) malloc(sizeof(FILM));
		if (head == NULL) {
		    return 1;
		}

	printf("\n<---- NETFLIX WATCHLIST ---->\n");
	printf("No films created. Please add one.\n");
	
	head->key=1;

	printf(" *Title: ");
	fflush(stdin);
	scanf("%[^\n]", &head->name);

	printf(" *Type: ");
	fflush(stdin);
	scanf("%[^\n]", &head->type);
	
	head->next= NULL;

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
			case 4: printList(head);  break; 
			case 9: control = 1; break;
			default: printf("Insert a valid value.\n");
		}
  	}while(control == 0);
	printf("Finaliza.\n");
}
