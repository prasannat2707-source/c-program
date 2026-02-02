#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct StudentDetails {
    char name[50];
    char dept[20];
};
struct StudentNode {
    int roll;
    struct StudentDetails details; 
    struct StudentNode *next;
};

struct StudentNode* createNode(int roll, char *name, char *dept) {
    struct StudentNode newNode = (struct StudentNode)malloc(sizeof(struct StudentNode));
    
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(0);
    }
    newNode->roll = roll;
    strcpy(newNode->details.name, name); 
    strcpy(newNode->details.dept, dept); 
    newNode->next = NULL;
    return newNode;
}
void displayList(struct StudentNode *head) {
    struct StudentNode *temp = head;
    while (temp != NULL) {
        printf("%d %s %s -> ", temp->roll, temp->details.name, temp->details.dept);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct StudentNode *head = NULL;
    struct StudentNode *temp = NULL;
    head = createNode(1, "Arun", "CSE");
    struct StudentNode *node2 = createNode(2, "Meena", "IT");
    head->next = node2;
    printf("Linked List Output:\n");
    displayList(head);

    return 0;
}