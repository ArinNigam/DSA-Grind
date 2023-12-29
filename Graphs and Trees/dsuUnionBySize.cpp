// Union by Size
// O(1) Time Complexity 
#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, size;    
public:
    void check(int x,int y){
        if (findUPar(x)==findUPar(y)){
            cout<<"Same"<<endl;
        }
        else{
            cout<<"Not Same"<<endl;
        }
    }
    DisjointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1,1);
        for (int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    int findUPar(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    DisjointSet ds(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ds.unionBySize(u,v);
    }
    int x,y;
    cin>>x>>y;
    ds.check(x,y);
    ds.unionBySize(x,y);
    ds.check(x,y);
    return 0;
}