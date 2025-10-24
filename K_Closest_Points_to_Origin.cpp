#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

vector<vector<int>>kClosest(vector<vector<int>> &points , int k){
    vector<vector<int>>ans;
    priority_queue<pair<int,pair<int,int>>>pq;
    for(auto &x : points){
        pq.push({abs(x[0]) * abs(x[0]) + abs(x[1]) * abs(x[1]) , {x[0] , x[1]}});
        if(pq.size() > k) pq.pop();
    }
    while(!pq.empty()){
        ans.push_back({pq.top().second.first , pq.top().second.second});
        pq.pop();
    }
    return ans;
}

int main(){

}