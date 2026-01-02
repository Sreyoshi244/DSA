#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
void LinkedListTraversal(struct Node* ptr){
    while (ptr!=NULL)
    {
        printf("%d ", ptr->data);
        ptr=ptr->next;
    }
}

//Insertion at the beginning
struct Node * insertAtFirst(struct Node* head, int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;

}
//Insertion in between
struct Node * insertAtIndex(struct Node* head, int data, int index){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    struct Node* p = head;    
    int i=0;
    while (i!=index-1)   //stop one node before the index
    {
        p=p->next;       //move p to next node
        i++;              
    }
    ptr->data=data;     //set data to new node
    ptr->next = p->next;
    p->next = ptr;
    return head;

}

//Insertion at the end
struct Node * insertAtEnd(struct Node* head, int data){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;    
    struct Node* p = head;
    int i=0;
    while (p->next!=NULL)  
    {
        p=p->next;       //move p to next node
        i++;              
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;

}


//Insertion after a node
struct Node * insertAfterNode(struct Node* head, struct Node* prevNode, int data){
    struct Node* ptr=(struct Node*) malloc(sizeof(struct Node));
    ptr->data=data;    
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head; 

}

int main(){
    struct Node* head=(struct Node*) malloc(sizeof(struct Node));
    struct Node* second=(struct Node*) malloc(sizeof(struct Node));
    struct Node* third=(struct Node*) malloc(sizeof(struct Node));
    struct Node* fourth=(struct Node*) malloc(sizeof(struct Node));
    head->data=11;
    head->next=second;
    second->data=12;
    second->next=third; 
    third->data=13;
    third->next=fourth;
    fourth->data=14;
    fourth->next=NULL;

    LinkedListTraversal(head);
    // head = insertAtFirst(head, 7);
    // head = insertAtIndex(head, 9, 1);
    // head = insertAtEnd(head, 9);
    head = insertAfterNode(head, second, 10);
    LinkedListTraversal(head);



return 0;
}