// Find the Maximum Sum of Node Values (Hard)

// There exists an undirected tree with n nodes numbered 0 to n - 1. 
// You are given a 0-indexed 2D integer array edges of length n - 1, 
// where edges[i] = [ui, vi] indicates that there is an edge between 
// nodes ui and vi in the tree. You are also given a positive integer k, 
// and a 0-indexed array of non-negative integers nums of length n, 
// where nums[i] represents the value of the node numbered i

// Choose any edge [u, v] connecting the nodes u and v, and update their values as follows:
// nums[u] = nums[u] XOR k
// nums[v] = nums[v] XOR k

// Return the maximum possible sum of the values Alice can achieve by performing the operation any number of times.

// Input: nums = [1,2,1], k = 3, edges = [[0,1],[0,2]]
// Output: 6
// Explanation: Alice can achieve the maximum sum of 6 using a single operation:
// - Choose the edge [0,2]. nums[0] and nums[2] become: 1 XOR 3 = 2, and the array nums becomes: [1,2,1] -> [2,2,2].
// The total sum of values is 2 + 2 + 2 = 6.
// It can be shown that 6 is the maximum achievable sum of values.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<long long> v(n); 
        for (int i = 0; i < n; i++) {
            v[i] = (nums[i] ^ k) - nums[i];
        }
        sort(v.rbegin(), v.rend());

        long long res = 0;
        for (int num : nums) {
            res += num;
        }

        for (int startInd = 0; startInd < n - 1; startInd += 2) {
            long long changingDelta = v[startInd] + v[startInd + 1]; // showing whether if would be beneficial if we XOR this two nodes 
            if (changingDelta > 0) {
                res += changingDelta;
            } else {
                break;
            }
        }

        return res;
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    int k;
    cin>>k;
    int x;
    cin>>x;
    vector<vector<int>>edges(x,vector<int>(2));
    for (int i=0;i<x;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j]; 
        }
    }
    Solution ob;
    auto ans = ob.maximumValueSum(nums,k,edges);
    cout<<ans;
    return 0;
}