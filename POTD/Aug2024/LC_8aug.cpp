// Spiral Matrix III (Medium)

// You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
// You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.
// Return an array of coordinates representing the positions of the grid in the order you visited them.

// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>dirn = {{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int x = 0;
        int window = 0;
        while(ans.size() < rows * cols){
            if (x == 0 || x==2){
                window++;
            }
            for(int i=0;i<window;i++){
                rStart+=dirn[x][0];
                cStart+=dirn[x][1];

                if (rStart>=0 && rStart < rows && cStart >=0 && cStart < cols){
                    ans.push_back({rStart,cStart});
                }
                if (ans.size() == rows * cols){
                    return ans;
                }
            }
            x= (x +1)%4;
        }
        return ans;
    }
};

signed main()
{    
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    Solution ob;
    auto ans = ob.spiralMatrixIII(n,m,x,y);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}