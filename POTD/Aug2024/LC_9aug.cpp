// Magic Squares In Grid (Medium)

// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
// Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?
// Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMagicSquare(vector<vector<int>>&grid,int i,int j){
        int n = grid.size();
        int m = grid[0].size();
        int col[3];
        int row[3];
        int diag[2];
        if (i + 2 < n && j + 2 < m){
            col[0] = grid[i][j] + grid[i+1][j] + grid[i+2][j];
            col[1] = grid[i][j+1] + grid[i+1][j+1] + grid[i+2][j+1];
            col[2] = grid[i][j+2] + grid[i+1][j+2] + grid[i+2][j+2];
            row[0] = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            row[1] = grid[i+1][j] + grid[i+1][j+1] + grid[i+1][j+2];
            row[2] = grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2];
            diag[0] = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            diag[1] = grid[i+2][j] + grid[i+1][j+1] + grid[i][j+2];
            if (col[0] == col[1] && col[0]==col[2] && col[0] == row[0] && col[0] == row[1] && col[0] == row[2] && col[0] == diag[0] && col[0] == diag[1]){
                set<int>st{1,2,3,4,5,6,7,8,9};
                for(int x = 0; x< 3; x++){
                    for(int y = 0 ; y<3; y++){
                        st.erase(grid[i + x][j + y]);
                    }
                }
                return st.size()==0;
            }
        }
        return false;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isMagicSquare(grid, i, j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};

signed main()
{  
  int n,m;
  cin>>n>>m;
  vector<vector<int>>grid(n,vector<int>(m));
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      cin>>grid[i][j];
    }
  }
  Solution ob;
  auto ans = ob.numMagicSquaresInside(grid);
  cout<<ans;
  return 0;
}