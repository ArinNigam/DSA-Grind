// Maximise (E[i]^D[i])
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int>temp;
    unordered_map<int,vector<int>>mp;
    void dfs(int node,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        vector<int>t(temp.begin(),temp.end());
        mp[node] = t;
        temp.push_back(node);
        for (auto it:adj[node]){
            if (!vis[it]){
                dfs(it,vis,adj);
            }
        }
        temp.pop_back();
    }
    vector<int> solve(int A, vector<int> &B, int C, vector<int> &D, vector<int> &E) {
        vector<vector<int>>adj(A+1);
        for (int i=1;i<A;i++){
            adj[B[i-1]].push_back(i+1);
        }
        // for (auto i:adj){
        //   for (auto j:i){
        //     cout<<j<<" ";
        //   }
        //   cout<<endl;
        // }
        vector<int>vis(A,0);
        vector<int>ans;
        dfs(1,vis,adj);
        // for (auto it:mp){
        //     cout<<it.first<<" ";
        //     for (auto j:it.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int i=0;i<C;i++){
            int maxi = (E[i]^D[i]);
            for (auto x:mp[D[i]]){
                maxi = max(maxi,(E[i]^x));
            }
            ans.push_back(maxi);
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        return ans;
    }

};

signed main()
{    
    int a,c;
    cin>>a>>c;
    vector<int>B(a),D(c),E(c);
    for (int i=0;i<a-1;i++){
        cin>>B[i];
    }
    for (int i=0;i<c;i++){
        cin>>D[i];
    }
    for (int i=0;i<c;i++){
        cin>>E[i];
    }
    Solution ob;
    auto ans = ob.solve(a,B,c,D,E);
    
    return 0;
}