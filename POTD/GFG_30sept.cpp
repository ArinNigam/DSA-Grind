// Boolean matrix
// Convert all rows and col to 1's if matrix[i][j] = 1
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void booleanMatrix(vector<vector<int> > &matrix)
    {
        // code here 
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>row(n,0);
        vector<int>col(m,0);
        
        for (int i = 0;i<n;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][j]==1){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (row[i]==1 || col[j]==1){
                    matrix[i][j] = 1;
                }
            }
        }
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.booleanMatrix(nums);
    cout<<ans;
    return 0;
}