#include<bits/stdc++.h>
using namespace std;

int dfs(vector<pair<int,int>>&g, vector<int>& vis, int node, int cost, int target)
{
    if(node==target) return cost;
    int ans=0;
    for(auto it: g[node])
    {
        int child=it.first;
        int wt=it.second;
        if(vis[child])continue;
        vis[child]=1;
        ans=max(ans,dfs(g, vis, child, min(cost,wt), target));
        vis[child]=0;
    }
    return min(ans, cost);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    vector<vector<pair<int,int>>>g(n+1);
    vector<int>vis(n+1,0);
    for (int i = 0; i <m; i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        g[x].push_back({y,wt});
    }
    cout<<dfs(g, vis, a, INT_MAX, b)<<endl;
}
signed main()
{    
    solve();
    return 0;
}