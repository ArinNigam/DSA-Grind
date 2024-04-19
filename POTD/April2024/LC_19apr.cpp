// Number of Islands (Medium)

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>&nums){
        if (x<0 || y<0 || x>=nums.size() || y>=nums[0].size() || nums[x][y]=='0'){
            return;
        }
        nums[x][y] = '0';
        dfs(x-1,y,nums);
        dfs(x+1,y,nums);
        dfs(x,y-1,nums);
        dfs(x,y+1,nums);
    }
    int numIslands(vector<vector<char>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int cnt = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (nums[i][j]=='1'){
                    cnt++;
                    dfs(i,j,nums);
                }
            }
        }
        return cnt;

    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i];
        }
    }
    Solution ob;
    auto ans = ob.numIslands(nums);
    cout<<ans;
    return 0;
}