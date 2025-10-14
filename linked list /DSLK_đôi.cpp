#include<iostream>
using namespace std;

struct node{
    int data;
    node *prev;
    node *next;
};

node *makeNode(int x){
    node *newNode = new node;
    newNode -> data = x;
    newNode -> prev = NULL;
    newNode -> next = NULL;
    return newNode;
}

int sz(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head -> next;
    }
    return dem;
}

void duyet(node *head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

void themdau(node *&head , int x){
    node *newNode = makeNode(x);
    newNode -> next = head; // cho phần next của node mới trỏ vào node đầu tiên hiện tại 
    if(head != NULL) head -> prev = newNode;
    head = newNode;
}

void themcuoi(node *&head , int x){
    node *newNode = makeNode(x);
    node *tmp = head;
    if(head == NULL){
        head = newNode;
        return;
    }
    while(tmp -> next != NULL){
        tmp = tmp -> next;
    }
    tmp -> next = newNode;
    newNode -> prev = tmp;
}

void themgiua(node *&head , int k , int x){
    node *newNode = makeNode(x);
    int n = sz(head);  
    if(k < 1 || k > n + 1) return;
    if(k == 1){
        themdau(head , x);
        return;
    }
    node *tmp = head;
    for(int i = 1;i <= k - 1;i++){
        tmp = tmp -> next;
    }
    newNode -> next = tmp;
    tmp -> prev -> next = newNode;
    newNode -> prev = tmp -> prev;
    tmp -> prev = newNode;
}

int main(){

}