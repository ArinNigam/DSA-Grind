#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int m, n;
    cin>>m>>n;
    vector<vector<int>>g(m+1);
    vector<int> vis(m+1, 0);
    
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int start;
    cin>>start;
    
    queue<pair<int,int>>q;

    q.push({start,0});
    vis[start]=1;
    int max_dist=1e9;
    int pos=0;
    
    while(!q.empty())
    {
        int node=q.front().first;
        int dist = q.front().second;
        q.pop();
        
        for(auto child: g[node])
        {
            if (dist+1 <=max_dist){
                max_dist= dist+1;
                q.push({child,max_dist});
                pos = child;
            }            
        }  
        
    }
    
    cout<<2*max_dist-1<<" "<<pos<<endl; 
}
void dijkstra(int V, vector<vector<int>>&adj, int start,vector<int>&dist)
{
    dist[start] = 0;
    
    queue<pair<int,int>> st; 
    st.push({0, start}); 
    
    while(!st.empty()) {
        // auto it = *(st.begin()); 
        int node = st.front().second; 
        int dis = st.front().first; 
        st.pop();
        for(auto it : adj[node]) {
            if(dis + 1 < dist[it]) {
                if(dist[it] != 1e9) {
                    st.pop(); 
                }
                dist[it] = dis + 1; 
                st.push({dist[it], it}); 
             }
        }
    }
    return; 
}
signed main()
{    
    int q;
    cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>graph(n+1);
        for (int i=0;i<m;i++){
            int u,v;
            cin>>u>>v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int start;
        cin>>start;
        int budget =0;
        int pos=0;
        vector<int> dist(n+1, 1e9);
        dijkstra(n,graph,start,dist);
        for (int i=1;i<=n;i++){
            if (budget<=dist[i] && dist[i]!=1e9){
                budget = dist[i];
                pos = i;
            }
        }
        cout<<2*budget+1<<" "<<pos<<endl;
    }
    
    return 0;
}