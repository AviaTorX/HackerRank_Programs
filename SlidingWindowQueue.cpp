#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
void enQueue(node **front, node **rear, int data){
    node *ptr = *front;
    node *ptr1 = *rear;
    node *newnode = new node;
    newnode -> data = data;
    newnode -> next = NULL;
    if(ptr1 ==  NULL && ptr == NULL){
        *front = newnode;
        *rear = newnode;
    }
    else{
        ptr1 -> next = newnode;
        *rear =newnode;
    }
}
void deQueue(node **front){
    node *ptr = *front;
    if(ptr == NULL){
        return ;
    }
    *front = ptr -> next;
    delete(ptr);
}
int main(){
    node *front = NULL;
    node *rear = NULL;
    long int n;
    cin>>n;
    long int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    long int w;
    cin>>w;
    long int max = 0, wholemax = 0;
    for(int i = 0; i <= n - w; i++){
        if(i  % w == 0){
            if(max > wholemax){
                wholemax = max;
            }
            cout<<max<<endl;
            max = 0;

            deQueue(&front);
            enQueue(&front, &rear, a[i]);
            max += a[i];
        }
        else{
            enQueue(&front, &rear, a[i]);
            cout<<max<<endl;
            max += a[i];

        }
    }
    //cout<<wholemax<<endl;
}