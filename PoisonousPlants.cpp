#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node *next;
};
void pushStackOne(node **top, int data){
    node *newnode = new node;
    newnode -> data = data;
    newnode -> next = *top;
    *top = newnode;
}
void pushStackTwo(node **top1, int data){
    node *newnode = new node;
    newnode -> data = data;
    newnode -> next = *top1;
    *top1 = newnode;
}
void popStackOne(node **top){
    node *temp = *top;
    *top = temp -> next;
    delete(temp);
}
void popStackTwo(node **top1){
    node *temp = *top1;
    *top1 = temp -> next;
    delete(temp);
}
int checkOrder(node **temp){
    return 0;
}
int main(){
    long int n;
    cin>>n;
    vector<long int> a;
    for(int i = 0; i < n; i++){
        long int x;
        cin>>x;
        a.push_back(x);
    }
    if(n == 1){
        cout<<"0"<<endl;
    }
    else{
        int i = 0;
        node *top1 = NULL;
        node *top = NULL;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] <= a[i - 1]){
                pushStackOne(&top, a[i]);
            }
        }
        pushStackOne(&top, a[0]);
        while(1){
             long int prev;
            if(i == 0){
                prev = top -> data;
                popStackOne(&top);
                pushStackTwo(&top1, prev);
                while(top != NULL){
                    long int z = top -> data;
                    popStackOne(&top);
                    if(prev >= z){
                        pushStackTwo(&top1, z);
                    }
                    prev = z;
                }
                if(!checkOrder(&top1)){
                    break;
                }
                i = 1;
            }
            else{
                prev = top1 -> data;
                popStackTwo(&top1);
                pushStackOne(&top1, prev);
                while(top1 != NULL){
                    long int z = top1 -> data;
                    popStackTwo(&top1);
                    if(prev >= z){
                        pushStackOne(&top1, z);
                    }
                    prev = z;
                }
                if(!checkOrder(&top)){
                    break;
                }
                i = 0;
            }
            /*if(!checkOrder(b)){
                break;
            }*/
        }
        node *temp;
        temp = top;
        cout<<"1st Stack"<<endl;
        while(temp != NULL){
            cout<<temp -> data<<endl;
            temp = temp -> next;
        }
        cout<<"\t\t 2nd Stack"<<endl;
        temp = top1;
        while(temp != NULL){
            cout<<temp -> data<<endl;
            temp = temp -> next;
        }
    }
}