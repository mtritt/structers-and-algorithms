// xây dựng lại 
#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node *next;
};

node *makeNode(int x){
    node *newNode = new node;
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

void duyet(node *head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int sizeList(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head -> next;
    }
    return dem;
}

void pushFront(node *&head , int x){
    // newNode là con trỏ hướng đến đối tượng kiểu node 
    node *newNode = makeNode(x);
    newNode -> next = head;
    head = newNode;
}

void pushBack(node *&head , int x){
    node *tmp = head;
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(tmp -> next != NULL) tmp = tmp -> next;   
    tmp -> next = NULL;
}

void insert(node *&head , int x , int k){
    int n = sizeList(head);
    if(k < 1 || k > n + 1) return;
    if(head == NULL){
        pushFront(head ,x);
        return;
    }
    node *tmp = head;
    for(int i = 1;i <= k - 2;i++){
        tmp = tmp -> next;
    }
    node *newNode = makeNode(x);
    newNode -> next = tmp -> next;
    tmp -> next = newNode;
}

int main(){

}