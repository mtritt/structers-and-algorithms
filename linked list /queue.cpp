#include<iostream>
using namespace std; 

// build queue by array 
// int a[1000000] , maxN = 1000000;
// int n = 0;

// int size(){return n;}

// bool empty(){return n == 0;}

// void push(int x){
//     if(n == maxN) return;
//     a[n] = x;
//     ++n;
// }

// void pop(){
//     if(n == 0) return;
//     for(int i = 0;i < n - 1;i++){
//         a[i] = a[i + 1];
//     }
//     n--;
// }

// int front(){
//     return a[0];
// }

// int main(){

// }

// build queue = linked list 
struct node{
    int data;
    node *next;
};

node *makeNode(int x){
    node *newNode = new node();
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

void push(node *&queue , int x){
    node *newNode = makeNode(x);
    if(queue == NULL){
        queue = newNode;
        return;
    }
    node *tmp = queue;
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
}

void pop(node *&queue){
    if(queue == NULL){
        return;
    }
    node *tmp = queue;
    queue = queue -> next;
    delete tmp;
}

int size(node *queue){
    int dem = 0;
    while(queue != NULL){
        dem++;
        queue = queue -> next;
    }
    return dem;
}

bool empty(node *&queue){
    return queue == NULL;
}

int front(node *queue){
    return queue -> data;
}

void duyet(node *queue){
    while(queue != NULL){
        cout << queue -> data << " ";
        queue = queue -> next;
    }
}


