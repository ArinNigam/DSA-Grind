// Find All Groups of Farmland (Medium)

// You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.

// To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are 
// called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.

// land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find 
// the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a 
// bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].


// Input: land = [[1,0,0],[0,1,1],[0,1,1]]
// Output: [[0,0,0,0],[1,1,2,2]]
// Explanation:
// The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
// The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,int &r,int &c,vector<vector<int>>&land){
        if (x<0 || y<0 || x>=land.size() || y>=land[0].size() || land[x][y]==0){
            return;
        }
        land[x][y] = 0;
        r = max(r,x);
        c = max(c,y);
        dfs(x-1,y,r,c,land);
        dfs(x+1,y,r,c,land);
        dfs(x,y-1,r,c,land);
        dfs(x,y+1,r,c,land);
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>ans;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                vector<int>v;
                if (land[i][j]==1){
                    int r = 0,c = 0;
                    dfs(i,j,r,c,land);
                    vector<int>v{i,j,r,c};
                    ans.push_back(v);
                }
                
            }
        }
        return ans;
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>nums(m,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findFarmland(nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}