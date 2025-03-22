#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PNUStudent {
    char name[20];
    char id[20];
    char major[30];
    char birthdate[20];
    struct PNUStudent* next;
} PNUStudent;

PNUStudent* createNode(const char* name, const char* id, const char* major, const char* birthdate) {
    PNUStudent* node = malloc(sizeof(PNUStudent));

    strcpy(node->name, name);
    strcpy(node->id, id);
    strcpy(node->major, major);
    strcpy(node->birthdate, birthdate);

    node->next = NULL;

    return node;
}

void insertNode(PNUStudent** head, PNUStudent* node) {
    PNUStudent* current = *head;
    PNUStudent* previous = NULL;

    while (current != NULL) {
        int nameComparison = strcmp(current->name, node->name);
        int idComparison = strcmp(current->id, node->id);
        if (0 < nameComparison || (nameComparison == 0 && 0 < idComparison)) {
            break;
        }
        previous = current;
        current = current->next;
    }
    
    if (previous == NULL) 
        *head = node;
    else 
        previous->next = node;
    
    node->next = current;
}

void modifyNode(PNUStudent* head, const char* id, const char* name, const char* major, const char* birthdate) {
    PNUStudent* current = head;

    // Implement your codes
    while(current != NULL){
        if(strcmp(current->id, id) == 0) {
            if (major != NULL) {
                strcpy(current->major, major);
            }
            if (birthdate != NULL) {
                strcpy(current->birthdate, birthdate);
            }
        }
        current = current->next;
    }
}

void deleteNode(PNUStudent** head, const char* id) {
    PNUStudent* current = *head;
    PNUStudent* previous = NULL;

    // Implement your codes

    while (current != NULL && strcmp(current->id, id) != 0) {
        // Implement your codes
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        // Implement your codes
        return;
    }
    if (previous == NULL) {
        // Implement your codes
        *head = current->next;
        return;
    }
    else {
        previous->next = current->next;
        // Implement your codes
    }

    free(current);

}

void printList(PNUStudent* head) {
    PNUStudent* current = head;
    printf("%-20s %-20s %-30s %-20s\n", "Name", "ID", "Major", "Birthdate");

    while (current != NULL) {
        printf("%-20s %-20s %-30s %-20s\n", current->name, current->id, current->major, current->birthdate);
        current = current->next;
    }

}

void freeList(PNUStudent* head) {
    PNUStudent* current = head;
    PNUStudent* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

}

 

int main() {
    PNUStudent* head = NULL;

    insertNode(&head, createNode("Winter", "202255578", "Engineering", "2003-04-30"));
    insertNode(&head, createNode("Leeseo", "201989330", "Education", "2000-07-28"));
    insertNode(&head, createNode("Jisoo", "201945456", "Social Science", "2000-02-17"));
    insertNode(&head, createNode("Rei", "202289851", "Natural Science", "2003-12-04"));
    insertNode(&head, createNode("Lisa", "202021344", "Entertainment & Sports", "2001-06-15"));
    insertNode(&head, createNode("Nayeon", "202255509", "Engineering", "2003-02-01"));
    insertNode(&head, createNode("Nayeon", "202021575", "Social Science", "2001-09-29"));
    insertNode(&head, createNode("Karina", "202245542", "Natural Science", "2003-02-24"));
    insertNode(&head, createNode("An Yujin", "202267318", "Social Science", "2003-08-22"));
    insertNode(&head, createNode("Jisoo", "201967365", "Humanities", "2000-10-06"));

    printf("\nModifying ...\n");
    modifyNode(head, "201967365", NULL, "Engineering", NULL);
    modifyNode(head, "202021575", NULL, "Entertainment & Sports", "2002-11-15");
    printList(head);

    printf("\nDeleting ...\n");
    deleteNode(&head, "202267318");
    deleteNode(&head, "202289851");
    printList(head);
    
    freeList(head);

    return 0;

}