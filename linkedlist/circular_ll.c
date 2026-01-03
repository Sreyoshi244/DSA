#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

// void LinkedListTraversal(struct Node* head){
//     struct Node* ptr = head;
//     // ptr is starting from head so we first print the 1st element then start the while loop from 2nd element
//     printf("the element is %d \n ", ptr->data);     //print first element
//         ptr=ptr->next; 
//     while (ptr!=head)          
//     {
//         printf("the element is %d \n ", ptr->data);
//         ptr=ptr->next;   
//     }
// }


void LinkedListTraversal(struct Node* head){
    struct Node* ptr = head;
    // do while loop is used to ensure that the loop runs at least once
    do{
        printf("the element is %d \n ", ptr->data);
        ptr=ptr->next;   
    }while (ptr!=head)   ;
}

//Insertion at the beginning
struct Node * insertAtFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head->next;
    
    while(p->next!=head){
        p=p->next;
    }
    // at this point p is pointing to the last node of the circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}

int main(){
    struct Node* head=(struct Node*) malloc(sizeof(struct Node));
    struct Node* second=(struct Node*) malloc(sizeof(struct Node));
    struct Node* third=(struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*) malloc(sizeof(struct Node));
    
    head->data=1;
    head->next=second;
    
    second->data=2;
    second->next=third; 
    
    third->data=3;
    third->next=fourth;
    
    fourth->data=4;
    fourth->next=head; //making it circular

    LinkedListTraversal(head);
    printf("After insertion \n");
    head = insertAtFirst(head, 7);
    LinkedListTraversal(head);



return 0;
}