// Shortest path for a Knight to move on a ChessBoard

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long

//Pair Vector
#define ff first
#define ss second

const int INF=1e9+5;

int lev[9][9];
int visited[9][9];

char getX(string s){
	return s[0]-'a';
}
char getY(string s){
	return s[1]-'1';
}
bool isValid(int x,int y){
	return x>=0 && y>=0 && x<8 && y<8;
}


vector<pair<int,int>>movements={
	{-1,2},{1,2},
	{-1,-2},{1,-2},
	{2,-1},{2,1},
	{-2,-1},{-2,1}
};

int bfs(string source, string dest ){
	int sourceX=getX(source);
	int sourceY=getY(source);
	int destX=getX(dest);
	int destY=getY(dest);
	cout<<destX<<" "<<destY<<endl;
	queue<pair<int,int>>q;
	q.push({sourceX,sourceY});
	visited[sourceX][sourceY]=1;
	
	while(!q.empty()){
		pair<int,int>v=q.front();
		int x = v.ff , y =v.ss;
		q.pop();
		for (auto movement: movements){
			int childX = movement.ff + x;
			int childY = movement.ss + y;
			if (!isValid(childX,childY))continue;
			if(!visited[childX][childY]){
				q.push({childX,childY});
				lev[childX][childY]=lev[x][y]+1;
				visited[childX][childY]=1;
			}
		}
	}
	
	
	return lev[destX][destY];
}

void reset(){
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			lev[i][j]=0;
			visited[i][j]=0;
		}
	}
}
signed main()
{	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		reset();
		string s1,s2;
		cin>>s1>>s2;
		cout<<bfs(s1,s2)<<endl;
	}
	return 0;
}
