#include<iostream>
#include<algorithm>
using namespace std;

vector<vector<int>>a(1005 , vector<int>(1005));
vector<int>visisted(1005 , 0);
int n , m; 

void nhapMatrix(){
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x , y; cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) cout << a[i][j] << " ";
        cout << endl;
    }
}

void duyetDFS(int u){
    visisted[u] = 1;
    for(int v = 1;v <= n;v++){
        if(a[u][v] == 1 && !visisted[v]) duyetDFS(v);
    }
}

void duyetBFS(int u){
    queue<int>q;
    q.push(u);
    visisted[u] = 1;
    while(!q.empty()){
        auto top = q.front();q.pop();
        for(auto v : a[top]){
            if(v == 1 && !visisted[v]){
                q.push(v);
                visisted[v] = 1;
            }
        }
    }
}

int main(){

}