#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;   //points to prev node
    struct Node* next;
};

void traverseForward(struct Node* head){
    struct Node* ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void traverseBackward(struct Node* tail){
    struct Node* ptr = tail;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;       //moves backward
    }
    printf("\n");
}

struct Node* insertAtFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;    //New node becomes first → no previous node
    ptr->next = head;    //New node points to old head


    if(head != NULL){
        head->prev = ptr;  //Old head's previous points to new node
    }
    return ptr; // new head
}


struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(head == NULL){           //If list is empty → new node becomes head
        ptr->prev = NULL;
        return ptr;
    }

    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;                       //Reach last node
    }

    p->next = ptr;
    ptr->prev = p;

    return head;                   //Head does not change here
}
struct Node* insertAtIndex(struct Node* head, int data, int index){
    if(index == 0){
        return insertAtFirst(head, data);
    }

    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;

    while(i < index-1 && p != NULL){          //Move to one node before index
        p = p->next;
        i++;
    }

    if(p == NULL){
        printf("Index out of range\n");
        return head;
    }

    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;

    if(p->next != NULL){         //Fix backward link
        p->next->prev = ptr;
    }
    p->next = ptr;            


    return head;
}
struct Node* deleteAtFirst(struct Node* head){
    if(head == NULL){
        return NULL;                  //Empty list check
    }

    struct Node* temp = head;         //Store old head
    head = head->next;

    if(head != NULL){                 //New head has no previous node
        head->prev = NULL;
    }

    free(temp);
    return head;
}
struct Node* deleteAtEnd(struct Node* head){
    if(head == NULL){
        return NULL;
    }

    struct Node* p = head;
    while(p->next != NULL){
        p = p->next;                       //Reach last node
    }

    if(p->prev != NULL){                     //Detach last node
        p->prev->next = NULL;
    } else {
        head = NULL;                        //Single-node case
    }

    free(p);
    return head;
}
struct Node* deleteByValue(struct Node* head, int value){
    struct Node* p = head;

    while(p != NULL && p->data != value){
        p = p->next;
    }

    if(p == NULL){
        printf("Value not found\n");
        return head;
    }

    if(p->prev != NULL){
        p->prev->next = p->next;
    } else {
        head = p->next;
    }

    if(p->next != NULL){
        p->next->prev = p->prev;
    }

    free(p);
    return head;
}
int main(){
    struct Node* head = NULL;

    head = insertAtFirst(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtIndex(head, 15, 1);

    printf("Forward traversal:\n");
    traverseForward(head);

    printf("After deleting first:\n");
    head = deleteAtFirst(head);
    traverseForward(head);

    printf("After deleting value 20:\n");
    head = deleteByValue(head, 20);
    traverseForward(head);

    return 0;
}
