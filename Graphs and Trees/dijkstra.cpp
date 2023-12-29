#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<pair<int,int>>>&adj,int src){
        // u->{v,w}
        int n = adj.size();
        
        // set me dist from source to node
        // aur next neighbour
        set<pair<int,int>>st;
        vector<int>dist(n,1e9);
        
        st.insert({0,src});
    
        dist[src] = 0;
        
        while(!st.empty()){
            auto it =*(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            // traverse karo uske neighbours
            for (auto i:adj[node]){
                int adjNode = i.first;
                int edgeW = i.second;
                if (dis + edgeW < dist[adjNode]){
                    // erase kardo agar phele wala zyada tha
                    if (dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    // naya value update kar neighbour ke distance ka
                    dist[adjNode] = dis + edgeW;
                    // insert karde neighbour ke distance aur uske neighbour ko parent maan le next step me
                    st.insert({dist[adjNode],adjNode});   
                }
            }
            
        }
        
        return dist;
    }
};

signed main()
{    
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>>nums(n);
    for (int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        nums[u].push_back({v,w});
    }
    Solution ob;
    auto ans = ob.solve(nums,k);
    for (auto i:ans){
      cout<<i<<" ";
    }
    return 0;
}