// Input
// 8
// 0 1
// 0 2 
// 0 3
// 1 4 
// 1 5 
// 3 6 
// 6 7
// 4 2 3 -5 -1 3 -2 6 

// Ouput
// 6

// Maximise Sum for a level
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& edges,vector<int>values){
        int n = edges.size();
        vector<vector<int>>adj(n);
        for (int i=0;i<n-1;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        queue<int>q;
        q.push(0);
        int res = values[0];
        while(!q.empty()){
            int cnt= q.size();
            int sum = 0;
            while(cnt--){
                int node = q.front();
                q.pop();
                
                sum+=values[node];
                for (auto it:adj[node]){
                    q.push(it);
                }
            }
            res = max(res,sum);
        }
        return res;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>(2));
    for (int i=0;i<n-1;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.solve(edges,nums);
    cout<<ans;
    return 0;
}