//Prefix sum of Trees pre computed sum and Even cnt in tree
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

//Linear Vector
#define append push_back
#define pop() pop_back()
#define all(v) v.begin(),v.end()
#define maxV(v) *max_element(all(v))
#define minV(v) *min_element(all(v))
#define sum(v) accumulate(all(v),0)
#define sort(v) sort(all(v))

//Pair Vector
#define ff first
#define ss second

const int N=1e5+5;

vector<int>g[N];
int subtree_sum[N];
int ev_cnt[N];
int val[N];


void dfs(int vertex,int parent){
    
    if (vertex%2==0){
        ev_cnt[vertex]++;
    }
    
    //Take action on vertex after entering the vertex
    
    subtree_sum[vertex]+=vertex; // val[vertex]
    for (int child: g[vertex]){
        /*Take action on child before entering a child node*/
        
        if (child==parent) continue;
        dfs(child,vertex);
        /*Take action on child after exiting a child node*/
        subtree_sum[vertex]+=subtree_sum[child];
        ev_cnt[vertex]+=ev_cnt[child];
    }
    //Take action on vertex before exiting the vertex
}

signed main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].append(v);
        g[v].append(u);
    }
    dfs(1,0);
    for (int i=1;i<=n;i++){
        cout<<subtree_sum[i]<<" "<<ev_cnt[i]<<endl;    
    }
    
        
    
    return 0;
}
