// thuật toán sinh 
#include<iostream>
#include<algorithm>
using namespace std;


void generateBinary(int n){
    vector<int>arr(n , 0);

    while(true){
        for(int i = 0;i < n;i++) cout << arr[i] << " ";
        cout << endl;
        int i = n - 1;
        while(i >= 0 && arr[i] == 1){
            arr[i] = 0;
            i--;
        }
        if(i < 0) break;
        arr[i] = 1;
    }
}

void generateCombi(int n, int k){
    if(k <= 0 || k > n) return;
    vector<int>res(k);
    for(int i = 0;i < n;i++) res[i] = i + 1;
    while(true){
        for(int i = 0;i < n;i++) cout << res[i] << " ";
        cout << endl;
        int i = k - 1;
        while(i >= 0 && res[i] == n - k + i + 1){
            i--;
        }
        if(i < 0) break;
        res[i]++;
        for(int j = i + 1;j < n;j++) res[j] = res[j - 1] + 1;
    }
}

void generatePermu(int n){
    vector<int>res(n);
    for(int i = 0;i < n;i++) res[i] = i + 1;
    while(true){
        for(int i = 0;i < n;i++) cout << res[i] << " ";
        cout << endl;

        int i = n - 2;
        while(i >= 0 && res[i] > res[i + 1]) i--;
        if(i < 0) break;
        int j = n - 1;
        while(res[j] < res[i]) j--;
        int tmp = res[i];
        res[i] = res[j];
        res[j] = tmp;
        
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            tmp = res[l];
            res[l] = res[r];
            res[r] = tmp;
            l++;
            r--;
        }
    }
}


int main(){
    int n; cin >> n;
    generateBinary(n);
}