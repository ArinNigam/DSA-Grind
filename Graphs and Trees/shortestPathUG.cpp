//Shortest Path in Undirected Graph with unit distance
// INPUT
// 9 10 0
// 0 1
// 0 3
// 3 4
// 4 5 
// 5 6 
// 1 2
// 2 6
// 6 7
// 7 8
// 6 8
// OUTPUT
// 0 1 2 1 2 3 3 4 4
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<int>>& adj,int src){
        int n = adj.size();
        queue<int>q;
        vector<int>dist(n,1e9);
        
        dist[src] = 0;
        q.push(src);

        while(!q.empty()){
           int node = q.front(); 
           q.pop();
           
           for (auto child:adj[node]){
                if (dist[node]+1< dist[child]){
                    dist[child] = 1 + dist[node];
                    q.push(child);
                }
           }
        }
        for (int i=0;i<n;i++){
            if(dist[i]==1e9){
                dist[i] = -1;
            }
        }
        return dist;
    }
};

signed main()
{    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>>nums(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        nums[u].push_back(v);
       
    }
    Solution ob;
    auto ans = ob.solve(nums,k);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}