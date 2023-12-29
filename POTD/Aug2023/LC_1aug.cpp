// Combinations (Medium)
// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.

// Example 1:

// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
// Example 2:

// Input: n = 1, k = 1
// Output: [[1]]
// Explanation: There is 1 choose 1 = 1 total combination.
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= n

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int ind,int n,int k,vector<int>&temp,vector<vector<int>>&ans){
        if (ind==n){
            if (k==0){
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(ind+1);
        solve(ind+1,n,k-1,temp,ans);
        temp.pop_back();

        solve(ind+1,n,k,temp,ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,n,k,temp,ans);
        return ans;   
    }
};
signed main()
{    
    int n,k;
    cin>>n>>k;
    Solution ob;
    auto ans = ob.combine(n,k);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}