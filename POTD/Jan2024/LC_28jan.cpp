// Number of Submatrices That Sum to Target
// Given a matrix and a target, return the number of non-empty submatrices that sum to target.
// A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
// Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.
// Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
// Output: 4
// Explanation: The four 1x1 submatrices that only contain 0.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        int cnt =0;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        for (int i=1;i<=n;i++){
            for (int j=1;j<=m;j++){
                for (int k=i;k<=n;k++){
                    for (int l=j;l<=m;l++){
                        int ans = dp[i-1][j-1] + dp[k][l] - dp[i-1][l] - dp[k][j-1];
                        if (ans==target){
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<vector<int>>matrix(n,vector<int>(n));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    
    Solution ob;
    auto ans = ob.numSubmatrixSumTarget(matrix,k);
    cout<<ans;
    return 0;
}