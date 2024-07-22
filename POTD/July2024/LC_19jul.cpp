// Find Valid Matrix Given Row and Column Sums (Medium)

// You are given two arrays rowSum and colSum of non-negative integers where rowSum[i] is the sum of the elements in the ith row and colSum[j] is the sum of the elements of the jth column of a 2D matrix. In other words, you do not know the elements of the matrix, but you do know the sums of each row and column.
// Find any matrix of non-negative integers of size rowSum.length x colSum.length that satisfies the rowSum and colSum requirements.
// Return a 2D array representing any matrix that fulfills the requirements. It's guaranteed that at least one matrix that fulfills the requirements exists.

// Input: rowSum = [3,8], colSum = [4,7]
// Output: [[3,0],
//          [1,7]]
// Explanation: 
// 0th row: 3 + 0 = 3 == rowSum[0]
// 1st row: 1 + 7 = 8 == rowSum[1]
// 0th column: 3 + 1 = 4 == colSum[0]
// 1st column: 0 + 7 = 7 == colSum[1]
// The row and column sums match, and all matrix elements are non-negative.
// Another possible matrix is: [[1,2],[3,5]]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        vector<int> ans;
        for(int i=0;i<m;i++){
            int maxEle=0;
            int minInd=0,minEle=INT_MAX;
            for(int j=0;j<n;j++){
                if (minEle > nums[i][j]){
                    minEle = nums[i][j];
                    minInd = j; 
                }
            }
            for(int j=0;j<m;j++){
                if (maxEle < nums[j][minInd]){
                    maxEle = nums[j][minInd];
                }
            }

            if (maxEle == minEle){
                ans.push_back(maxEle);
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
    auto ans = ob.luckyNumbers(nums);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}