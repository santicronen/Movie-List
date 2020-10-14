void push(FILM *head, int id) {
    FILM *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = (FILM *) malloc(sizeof(FILM));
    current->next->id = id;
    current->next->next = NULL;
}
