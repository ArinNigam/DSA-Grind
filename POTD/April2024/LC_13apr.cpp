// Maximal Rectangle (Hard)

// Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

// matrix = 
//      [["1","0","1","0","0"]
//      ["1","0","1","1","1"]
//      ["1","1","1","1","1"]
//      ["1","0","0","1","0"]]
// Output: 6

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>&nums){
        int n = nums.size();
        stack<int>st;
        int left[n];
        int right[n];
        for (int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if (!st.empty()){
                left[i] = st.top();
            }
            else{
                left[i] = -1;
            }
            st.push(i);
        }
        
        while(!st.empty()){
            st.pop();
        }
        
        for (int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if (!st.empty()){
                right[i] = st.top();
            }
            else{
                right[i] = n;
            }
            st.push(i);
        }
        int maxi = 0;
        for (int i=0;i<n;i++){
            maxi = max(maxi,(right[i]-left[i]-1)*nums[i]);
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int>nums(m,0);
        int ans = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (matrix[i][j]=='0'){
                    nums[j] = 0;
                }
                else{
                    nums[j]+=1;
                }
            }
            ans = max(ans,solve(nums));
        }
        return ans;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<char>>nums(n,vector<char>(m,-1));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.maximalRectangle(nums);
    cout<<ans;
    return 0;
}