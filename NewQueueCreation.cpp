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
struct Queue *createQueue(){
    struct Queue *q = new Queue;
    if(!q)
        return NULL;
    q -> front = q -> rear = NULL;
    return q;
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
void display(Queue *q){
    node *ptr = q -> front;
    while(ptr != NULL){
        cout<<ptr -> data<<endl;
        ptr = ptr -> next;
    }
}
void deQueue(Queue *q){
    //Queue *temp = q;
    q -> front = q -> front -> next;
    //delete(temp);
}
int main(){
    Queue *q = createQueue();
    enQueue(q, 1);
    //cout<<q -> front -> data<<endl;
    enQueue(q, 2);
    enQueue(q, 3);
    enQueue(q, 4);
    enQueue(q, 5);
    enQueue(q, 6);
    enQueue(q, 7);
    //display(q);
    deQueue(q);
    display(q);
}