#include<iostream>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

struct node{
    int data;
    node *next;
};

int sumOfLastNode(node *head , int n){
    node *first = head;
    node *second = head;
    for(int i = 1;i <= n;i++) {
        first = first -> next;
        second = second -> next;
    }
    int sum = 0;
    while(second != NULL){
        sum += second -> data;
        second = second -> next;
    }
    return sum;
}

int main(){
    node *head = NULL;

}