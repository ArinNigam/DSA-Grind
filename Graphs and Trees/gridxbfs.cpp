#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

void bfs(vector<vector<char>>& grid,int pos,string s,queue<pair<int,int>>&q,set<pair<int,int>>&set){
  int m = grid.size();
  int n = grid[0].size();
  int len = s.size();
  
  int delrow[] = {-1,0,1,0,-1,1,-1,1};
  int delcol[] = {0,-1,0,1,-1,-1,1,1};
  
  if (pos>len) return;
  while(!q.empty()){
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    set.insert({x,y});
    for (int i=0;i<8;i++){
      int nrow = x + delrow[i];
      int ncol = y + delcol[i];
      if (nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == s[pos]){
        q.push({nrow,ncol});
      }
    }
    pos++;
  }
  
}
void dfs(int row,int col,vector<vector<char>>& grid,int x,string s,set<pair<int,int>>&set){
  int m = grid.size();
  int n = grid[0].size();
  int len = s.size();
  
  
  set.insert({row,col});
  int delrow[] = {-1,0,1,0,-1,1,-1,1};
  int delcol[] = {0,-1,0,1,-1,-1,1,1};
  for (int k=x;k<len;k++){
    vector<pair<int,int>>temp;
    for (int i=0;i<8;i++){
      int nrow = row + delrow[i];
      int ncol = col + delcol[i];
      if (nrow>=0 && ncol>=0 && nrow<m && ncol<n && grid[nrow][ncol] == s[k]){
        temp.push_back({nrow,ncol});
        dfs(nrow,ncol,grid,k+1,s,set);
      }
    } 
  }
} 
signed main()
{  
  int n,m;
  cin>>m>>n;
  string s;
  cin>>s;
  int len = s.size();
  vector<vector<char>>grid(m,vector<char>(n));
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }
  bool flag =1;
  set<pair<int,int>>set;
  queue<pair<int,int>>q;
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      if (grid[i][j]==s[0]){
        q.push({i,j});
        set.insert({i,j});
        bfs(grid,1,s,q,set);
        flag=0;
        break;
      }
    }
    if (flag==0){
      break;
    }
  }
  for (auto i:set){
    cout<<i.first<<" "<<i.second<<endl;
  }
  // if (set.size()==0){
  //   cout<<0<<" "<<-1<<" "<<-1<<" "<<-1<<" "<<-1;
  // }
  // else{
  //   auto it1 = set.begin();
  //   auto it2 = set.begin();
  //   advance(it1,0);
  //   advance(it2,n-1);
  //   cout<<set.size()<<" "<<(*it1).first<<" "<<(*it1).second<<" "<<(*it2).first<<" "<<(*it2).second;
  // }
  return 0;
}