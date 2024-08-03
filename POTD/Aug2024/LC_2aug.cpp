// Minimum Swaps to Group All 1's Together II

// A swap is defined as taking two distinct positions in an array and swapping the values in them.
// A circular array is defined as an array where we consider the first element and the last element to be adjacent.
// Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
// There is no way to group all 1's together with 0 swaps.
// Thus, the minimum number of swaps required is 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<int>temp;
        for(int j=0;j<2;j++){
            for(int i=0;i<n;i++){
                temp.push_back(nums[i]);
            }
        }
        int k = count(nums.begin(),nums.end(),1);
        int i = 0;
        int j = 0;
        int mini = n-k;
        for(j = 0;j<k;j++){
            mp[temp[j]]++;
        }
        mini = min(mini,mp[0]);
        while(i+k<2*n){
            mp[temp[i++]]--;
            mp[temp[j++]]++;
            mini = min(mini,mp[0]);
        }
        return mini;
        
        
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
    Solution ob;
    auto ans = ob.minSwaps(nums);
    cout<<ans;
    return 0;
}