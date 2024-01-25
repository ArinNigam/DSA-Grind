#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve(){
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for (int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0;
    int k=1;
    while(k<n){
        i =0;
        priority_queue<int,vector<int>,greater<int>>pq;
        while(i+k<n){
            pq.push(abs(v[i+k]-v[i]));
            i++;
        }
        if (pq.top()>=d){
            cout<<k+1;
            return;
        }
        k++;
    }
   
    
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;
}
