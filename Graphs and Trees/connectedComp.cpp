//To find number of connected components

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
bool visited[N];

int n,e;
void dfs(int vertex){
	
	visited[vertex]=true;
	//Take action on vertex after entering the vertex
	
	for (int child: g[vertex]){
		
		if (visited[child]) continue;	
		/*Take action on child before entering a child node*/
		
		dfs(child);
		/*Take action on child after exiting a child node*/
	}
	//Take action on vertex before exiting the vertex
}
    
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].append(v);
			g[v].append(u);
		}
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (visited[i]) continue;
			dfs(i);
			cnt++;
		}
		
		cout<<cnt<<endl;
	}
	
	
	return 0;
}
