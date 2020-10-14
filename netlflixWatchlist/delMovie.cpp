struct FILM* delete(struct FILM *head, int key){

 //start from the first link
 struct FILM* current = head;
 struct FILM* previous = NULL;
  
  //if list is empty
 if(head == NULL) {
    return NULL;
 }

 //navigate through list
 while(current->key != key) {

      //if it is last FILM
     if(current->next == NULL) {
       return NULL;
     } else {
       //store reference to current link
       previous = current;
       //move to next link
       current = current->next;
     }
 }

 //found a match, update the link
 if(current == head) {
    //change first to point to next link
    head = head->next;
 } else {
     //bypass the current link
    previous->next = current->next;
  }    
  
  return current;
}

