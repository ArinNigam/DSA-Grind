#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void toggleRow(int i,vector<vector<int>>&grid,int col){
        for (int j=0;j<col;j++){
            if (grid[i][j]==0){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    void toggleCol(int j,vector<vector<int>>&grid,int row){
        for (int i=0;i<row;i++){
            if (grid[i][j]==0){
                grid[i][j] = 1;
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (n==1 && m==1){
            return 1;
        }
        for (int i=0;i<m;i++) {
            if (grid[i][0] == 0) {
                toggleRow(i,grid,n);
            }
        }
        for (int j=1;j<n;j++){
            int cnt = 0;
            for (int i=0;i<m;i++){
                cnt+=grid[i][j];
            }
            if (cnt < m-cnt){
                toggleCol(j,grid,m);
            }
        }
        int sum = 0;
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                sum+= grid[i][j]*1<<(n-j-1);   
            }
        }
        return sum;
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>nums(m,vector<int>(n));
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.matrixScore(nums);
    cout<<ans;
    return 0;
}