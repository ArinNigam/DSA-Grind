#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int N=1e3+5;
int orangesRotting(vector<vector<int>>&grid) {
    int m = grid.size();
    int n = grid[0].size();
    int cnt =0,tot=0,days=0;
    queue<pair<int,int>> q;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            if (grid[i][j]==2) q.push({i,j});
            if (grid[i][j]!=0) tot++;
        }
    }
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    while(!q.empty()){
        int k = q.size();
        cnt+=k;
        while(k--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]!=1) continue;
                grid[nx][ny]=2;
                q.push({nx,ny});
            }
        }
        if (!q.empty()){
            days++;
        }
    }
    if (tot == cnt){
        return days;
    }
    else{
        return -1;
    }
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(m,vector<int>(n));
  for (int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }
  
  cout<<orangesRotting(grid);
    
}