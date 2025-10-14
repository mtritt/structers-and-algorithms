#include<iostream>
using namespace std;

// build stack = array 
// int n = 0 , st[10001];

// void push(int x){
//     st[n] = x;
//     n++;
// }

// void pop(){
//     if(n >= 1) n--;
// }

// int top(){
//     return st[n - 1];
// }

// int size(){
//     return n;
// }

// build stack = linked list 
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

void push(node *&top , int x){
    node *newNode = makeNode(x);
    if(top == NULL){
        top = newNode;
        return;
    }
    newNode -> next = top -> next;
    top = newNode;
}

void pop(node *&top){
    if(top != NULL){
        node *tmp = top;
        top = tmp -> next;
        delete tmp;
    }
}

int Top(node *&top){
    if(top == NULL){
        return top -> data;
    }
}

int size(node *top){
    int dem = 0;
    while(top != NULL){
        dem++;
        top = top -> next;
    }
    return dem;
}

int main(){
    node *st = NULL;
    
}





