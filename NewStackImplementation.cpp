#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
struct Stack{
    struct node *top;
};
struct Stack *createStack(){
    Stack *s = new Stack;
    s -> top = NULL;
    return s;
}
void push(Stack *s, int data){
    node *newnode = new node;
    newnode -> data = data;
    if(s == NULL){
        newnode -> next = NULL;
        s -> top = newnode;
    }
    else{
        newnode -> next = s -> top;
        s -> top = newnode;
    }
}
void display(Stack *s){
    Stack *temp = s;
    while(temp -> top != NULL){
        cout<<temp -> top -> data<<endl;
        temp -> top = temp -> top -> next;
    }
}
void pop(Stack *s){
    s -> top = s -> top -> next;
}
int main(){
    Stack *s = createStack();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    push(s, 6);
    push(s, 7);
    
    pop(s);
    display(s);
}