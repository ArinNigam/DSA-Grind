// Word Search (Medium)
// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int x,int y,int ind,vector<vector<char>>& board,vector<vector<int>>&vis,string &word){
        int n = board.size();
        int m = board[0].size();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        
        vis[x][y] = 1;
        
        if (ind==word.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i]; 
            int ny = y + dy[i];
            if (nx>=0 && ny>=0 && nx<n && ny<m && board[nx][ny]==word[ind] && !vis[nx][ny]){
                if (dfs(nx,ny,ind+1,board,vis,word)){
                    return true;
                }
                else{
                    vis[nx][ny] = 0;
                }
            }
            
        }
        return false;
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (board[i][j]==word[0]){
                    if (dfs(i,j,1,board,vis,word)){
                        return true;
                    }
                    else{
                        vis[i][j] = 0;
                    }
                }
            }
        }
        return false;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(m,vector<char>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    string word;
    cin>>word;
    Solution ob;
    auto ans = ob.exist(board,word);
    cout<<ans;
    return 0;
}