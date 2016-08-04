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
    if(ptr == NULL && ptr1 == NULL){
        *front = newnode;
        *rear = newnode;
    }
    else{
        ptr1 -> next = newnode;
        *rear = newnode;
    }
}
int main(){
    long int n, k;
    cin>>n>>k;
    long int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(n == 1){
        if(a[0] >= k){
            cout<<"0"<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    else{
        node *front = NULL;
        node *rear = NULL;
        long int x = a[0] + (2 * a[1]);
        enQueue(&front, &rear, x);
        for(int i = 2; i < n; i++){
            if(a[i] >= k && front -> data >= k){
                break;
            }
            else if(a[i] < k && front -> data >= k){
                
            }
            else if(a[i] >= k && front -> data < k){

            }
        }
    }
}