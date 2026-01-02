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

//deletion at the beginning
struct Node * deleteAtFirst(struct Node* head){
    struct Node* p = head;  //create a pointer p and point it to head
    head = head->next;
    free(p);
    return head;
    

}
//delete in between
struct Node * deleteAtIndex(struct Node* head, int index){
    
    struct Node* p = head;    
    struct Node* q=p->next; //node to be deleted
    int i=0;
    for (i=0;i<index-1;i++)   //stop one node before the index
    {
        p=p->next;       
        q=q->next;
    }
    p->next = q->next;
    free(q);
    return head;

}

//delete at the end
struct Node * deleteAtEnd(struct Node* head){
      
    struct Node* p = head;
    struct Node* q=p->next; 
    int i=0;
    while (q->next!=NULL)  
    {
        p=p->next; 
        q=q->next;      //move q to next node
        i++;              
    }
    
    p->next = NULL;
    free(q);
    return head;

}


//delete a value
struct Node * deleteValue(struct Node* head, int value){
    struct Node* p = head;    
    struct Node* q=p->next; //node to be deleted
    int i=0;
    while(q->data!=value && q->next!=NULL) 
    {
        p=p->next;       
        q=q->next;
    }
    if(q->data==value){
        p->next = q->next;
        free(q);
    }
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

    printf("Linked list before deletion\n");

    LinkedListTraversal(head);

    printf("\nLinked list after deletion\n");

    // head = deleteAtFirst(head);
    // head = deleteAtIndex(head, 1);
    // head = deleteAtEnd(head);
    head = deleteValue(head, 12);
    LinkedListTraversal(head);



return 0;
}