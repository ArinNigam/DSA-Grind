#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,int parent,unordered_set<char>&st,vector<vector<int>>&adj,vector<char>&ans,int flag){
        for(auto it:adj[node]){
            if (it!=parent){
                if (st.find(it+'A')!=st.end() || flag){
                    ans.push_back(it+'A');
                    dfs(it,node,st,adj,ans,1);
                }
                else{
                    dfs(it,node,st,adj,ans,0);
                }
            }
        }
        
    }
    vector<char> projects(vector<vector<char>>&dependency,vector<char>&D){
        vector<vector<int>>adj(26);
        vector<int> indegree(26,INT_MAX);
        for(auto dep:dependency){
            adj[dep[1]-'A'].push_back(dep[0]-'A');
            indegree[dep[0]-'A']++;
            if (indegree[dep[1]-'A']==INT_MAX){
                indegree[dep[1]-'A'] = 0;
            }
        }
        unordered_set<char>st(D.begin(),D.end());
        set<char>res;
        for(int i=0;i<26;i++){
            vector<char> ans;
            if (indegree[i] == 0){
                dfs(i,-1,st,adj,ans,0);
                
            }
            for(int i=0;i<ans.size();i++){
                res.insert(ans[i]);
            }
        }
        vector<char>ans(res.begin(),res.end());
        return ans;  
    }
};

signed main()
{    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int k,j;
        cin>>k>>j;
        vector<vector<char>>dependency(k,vector<char>(2));
        for(int i=0;i<k;i++){
            cin>>dependency[i][0]>>dependency[i][1];
        }
        vector<char>D(j);
        for(int i=0;i<j;i++){
            cin>>D[i];
        }
        Solution ob;
        auto ans = ob.projects(dependency,D);
        cout<<"Case #"<<i<<": ";
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}