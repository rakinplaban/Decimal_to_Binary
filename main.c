#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
}*node;
struct Head{
    int count;
    struct Head* front;
    struct Head* rare;
}*head;
struct Node* createNode(int data){
    node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}
struct Head* createQueue(){
    head = (struct Head*)malloc(sizeof(struct Head));
    head->count = 0;
    head->front = NULL;
    head->rare = NULL;
    return head;
}
void enqueue(struct Head* head,int data);
void dequeue(struct Head* head);
void display(struct Head* head);
int main()
{
    int n,m = 0;
    struct Head* q = createQueue();
    scanf("%d",&n);
    int k = n;
    do{
        m = n%2;
        n = n/2;
        enqueue(q,m);
    }while(n!=0);
    printf("The binary form of %d is :",k);
    display(q);
    return 0;
}
void enqueue(struct Head* head,int data){
    createNode(data);
    if(head->count == 0){
        head->front = node;
        head->rare = node;
        head->count++;
    }
    else{
        struct Node* temp;
        temp = head->rare;
        head->rare = node;
        node->next = temp;
        head->count++;
    }
}

void dequeue(struct Head* head){
    if(head->count==0)
        printf("Underflow");
    struct Node* temp;
    temp = head->rare;
    while(temp->next->next!= NULL){
        temp = temp->next->next;
    }
    if(temp->next->next==NULL){
        head->front = temp->next;
        free(temp->next->next);
        head->count--;
    }
}
void display(struct Head* head){
    if(head->count == 0)
        printf("Queue is Empty!");
    else{
        struct Node* temp;
        temp = head->rare;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp = temp->next;
        }
    }
}
