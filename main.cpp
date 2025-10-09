// First negative in every window of size k
#include<iostream>
#include<algorithm>
using namespace std;

//clang++ -stdlib=libc++ main.cpp -o main
//./main 


vector<int>firstNeInt(vector<int> &arr , int k){
    int n = arr.size();
    vector<int>res;
    deque<int>dq;

    for(int i = 0;i < k;i++){
        if(arr[i] < 0){
            dq.push_back(i);
        }
    }

    if(!dq.empty()) res.push_back(arr[dq.front()]);
    else res.push_back(0);

    for(int i = k;i < n;i++){
        // nếu phần tử đinh dq không nằm trong window hiện tại a
        if(!dq.empty() && dq.front() == i - k) dq.pop_back();
        if(arr[i] < 0) dq.push_back(i);
        if(!dq.empty()) res.push_back(arr[dq.front()]);
        else res.push_back(0);
    }
    return res;
}

int main(){
    int n , k; cin >> n >> k;
    vector<int>arr(n);
    for(auto &x : arr) cin >> x;

    vector<int>res = firstNeInt(arr , k);

    for(auto x : res) cout << x << " ";
    cout << endl;
}