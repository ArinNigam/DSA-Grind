//Parallel Courses III
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n+1);
        vector<int>indeg(n+1);
        for(auto it: relations){
            adj[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        vector<int>wait(n+1);
        queue<int>q;
        int maxWait = 0;
        for (int i=1;i<=n;i++){
            if(indeg[i]==0){
                q.push(i);
                wait[i] = time[i-1];
                maxWait = max(wait[i],maxWait);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for (auto it: adj[node]){
                indeg[it]--;
                wait[it] = max(time[it-1] + wait[node],wait[it]);
                maxWait = max(maxWait,wait[it]);
                if (indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return maxWait;
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<m;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    vector<int>time(n);
    for (int i=0;i<n;i++){
        cin>>time[i];
    }
    Solution ob;
    auto ans = ob.minimumTime(n,nums,time);
    cout<<ans;
    return 0;
}