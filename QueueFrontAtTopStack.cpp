#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
struct Queue{
    struct node *front;
    struct node *rear;
};
struct Stack{
    struct node *top;
};
struct Queue *createQueue(){
    struct Queue *q = new Queue;
    q -> front = NULL;
    q -> rear = NULL;
    return q;
}
struct Stack *createStack(){
    struct Stack *s = new Stack;
    s -> top = NULL;
    return s;
}
void enQueue(Queue *q, int data){
    Queue *temp = q;
    node *newnode = new node;
    newnode -> data = data;
    newnode -> next = NULL;
    if(temp -> rear){
        temp -> rear -> next = newnode;
    }
    temp -> rear = newnode;
    if(temp -> front == NULL){
        temp -> front = temp -> rear;
    }
    q = temp;
}
void deQueue(Queue *q){
    node *temp = q -> front;
    q -> front = q -> front -> next;
    if(q -> front == NULL){
        q -> rear = NULL;
    }
    delete(temp);
}
void push(Stack *s, int data){
    node *newnode = new node;
    newnode -> data = data;
    newnode -> next = s -> top;
    s ->top = newnode;
}
void pop(Stack *s){
    node *temp = s -> top;
    s -> top = s -> top -> next;
    delete(temp);
}
void display(Stack *s){
    Stack *temp = s;
    while(temp -> top != NULL){
        cout<<temp -> top -> data<<endl;
        temp -> top = temp -> top -> next;
    }
}
void displayQueue(Queue *q){
    node *ptr = q -> front;
    while(ptr != NULL){
        cout<<ptr -> data<<endl;
        ptr = ptr -> next;
    }
}
int main(){
    Queue *q = createQueue();
    Stack *s = createStack();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    //displayQueue(q);
    while(q -> front != NULL){
        push(s, q -> front -> data);
        deQueue(q);
    }
    while(s -> top != NULL){
        enQueue(q, s -> top -> data);
        pop(s);
    }
    while(q -> front != NULL){
        push(s, q -> front -> data);
        deQueue(q);
    }
    display(s);
}