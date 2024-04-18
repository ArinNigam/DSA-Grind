// Island Perimeter (Easy)

// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int peri = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (nums[i][j]==1){
                    peri+=dfs(i,j,nums);
                }
            }
        }
        return peri;
    }
    int dfs(int x,int y,vector<vector<int>>&nums){
        if (x<0 || y<0 || x>=nums.size() || y>=nums[0].size() || nums[x][y] == 0){
            return 1;
        }
        if (nums[x][y]==-1){
            return 0;
        }
        
        nums[x][y] = -1;
        
        return dfs(x-1,y,nums) + dfs(x+1,y,nums) + dfs(x,y-1,nums) + dfs(x,y+1,nums); 
        
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.islandPerimeter(nums);
    cout<<ans;
    return 0;
}