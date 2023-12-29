// Alien Dictionary
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,stack<int>&st,vector<int>&vis,vector<vector<int>>&adj){
        vis[node] = 1;
        for (auto it: adj[node]){
            if (!vis[it]){
                dfs(it,st,vis,adj);
            }
        }
        st.push(node);
    }
    string getAlienLanguage(vector<string> &dictionary, int k)
    {
        int n = dictionary.size();
        vector<vector<int>>adj(k);
        for (int i=0;i<n-1;i++){
            string s1 = dictionary[i];
            string s2 = dictionary[i+1];
            for (int j=0;j<min(s1.size(),s2.size());j++){
                if (s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int>vis(k,0);
        stack<int>st;
        for (int i=0;i<k;i++){
            if (!vis[i]){
                dfs(i,st,vis,adj);
            }
        }
        string s;
        while(!st.empty()){
            s+= 'a' + st.top();
            st.pop();
        }
        return s;
        
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<string>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.getAlienLanguage(nums,k);
    cout<<ans;
    return 0;
}