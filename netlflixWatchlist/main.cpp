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
//#include "addmovie.cpp"
//#include "delmovie.cpp"

void menu(){

  int option;

  printf("<---- NETFLIX WATCHLIST ---->\n");
  printf("Select an option below.\n");
  printf("1. Add a film.\n");
  printf("2. Delete a film.\n");
  printf("3. Modify a film.\n");
	printf("Selection? ");

  scanf("%d", &option);
  switch(option){
    case 1: // push
    case 2: // delete
    case 3: // modify
    default: printf("Insert a valid value."); menu();
  }
  
  
  
}

int main(){
  FILM *head = NULL;

  head = (FILM *) malloc(sizeof(FILM));
	if (head == NULL) {
	    return 1;
	}

  menu();
}
