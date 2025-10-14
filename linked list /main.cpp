// danh sách liên kết 
// có thể mở rộng và thu hẹp một cách linh hoạt 
#include<iostream>
#include<algorithm>
using namespace std;

// cấu trúc tự trỏ 
// 1 con trỏ sẽ chưa 2 phần đó là data và địa chỉ của node tiếp theo 
// để lưu địa chỉ của node tiếp theo thì trong đó phải có con trỏ hay cấu trúc tự trỏ 

struct node{
    int data;
    node *next;
};

// struct SinhVien{
//     string name;
//     double gpa;
//     SinhVien(){}
//     SinhVien(string ten , double diem){
//         name = ten;
//         gpa = diem;
//     }
// };

// struct node{
//     SinhVien data;
//     node *next;
// };

// tạo node mới 
node *makeNode(int x){
    node *newNode = new node();
    newNode -> data = x;
    newNode -> next = NULL;
    return newNode;
}

// di chuyển con trỏ head hiện tại sang node tiếp theo 
void duyet(node *head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int count(node *head){
    int dem = 0;
    while(head != NULL){
        dem++;
        head = head -> next;
    }
    return dem;
}

// đưa node vào đầu ds 
void pushFront(node *&head , int x){
    node *newNode = makeNode(x);
    newNode -> next = head;// *head : địa chỉ của node head trong dslk 
    // cập nhật node head 
    head = newNode;
}

// đưa node vào cuối ds 
void pushBack(node *&head , int x){
    node *tmp = head;
    node *newNode = makeNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    while(tmp -> next != NULL){
        tmp = head -> next;
    }
    // next của head trỏ vào new node 
    tmp -> next = newNode;
}

// chèn node vào giữa dslk 
void insert(node *&head ,int k, int x){
    int n = count(head);
    if(k < 1 || k > n + 1) return;
    if(k == 1) pushFront(head , x);
    node *tmp = head;
    for(int i = 1;i <= k - 2;i++){
        tmp = tmp -> next;
    }
    node *newNode = makeNode(x);
    newNode -> next = tmp -> next;
    tmp -> next = newNode;
}

// xoá node đầu ds
void popFront(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    head = head -> next;
    delete tmp;
}

// xoá node cuối ds
void popBack(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    if(tmp -> next == NULL) {
        head = NULL;
        delete tmp;
        return;
    }
    while(tmp -> next -> next != NULL){
        tmp = tmp -> next;
    }
    node *last = tmp -> next;
    tmp -> next = NULL;
    delete tmp;
} 

void erase(node *&head , int k){
    int n = count(head);
    if(k < 1 || k > n) return;
    if(k == 1) popFront(head);
    else {
        node *tmp = head;
        for(int i = 1;i <= k - 2;i++){
            tmp = tmp -> next;            
        }
        node *kth = tmp -> next;
        tmp -> next = kth -> next;
        delete kth;
    }
}

// sắp xếp data chứ không quan tâm đến địa chỉ 
// selection sort 
void sx(node *&head){
    for(node *i = head;i != NULL;i = i -> next){
        node *minNode = i;
        for(node *j = i -> next;j != NULL; j = j -> next){
            if(minNode -> data > j -> data){
                minNode = j;
            }
        }
        int tmp = minNode -> data;
        minNode -> data = i -> data;
        i -> data = tmp;
    }
}

int main(){
    // node *head = NULL;
    // for (int i = 1;i <= 5;i++){
    //     pushFront(head , i);
    // }
    // for (int i = 3;i <= 9;i++){
    //     pushBack(head ,i);
    // }
    // duyet(head);
    // return 0;

    node *head = NULL;
    int a[] = {10 , 9 , 8 , 4 , 5 , 3 , 6 , 7};
    for(int i = 1;i <= 10;i++){
        pushBack(head , a[i]);
    }
    sx(head);
    duyet(head);
}