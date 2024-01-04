// Minimum Number of Operations to Make Array Empty (Medium)

// Input: nums = [2,3,3,2,2,4,2,3,4]
// Output: 4
// Explanation: We can apply the following operations to make the array empty:
// - Apply the first operation on the elements at indices 0 and 3. The resulting array is nums = [3,3,2,4,2,3,4].
// - Apply the first operation on the elements at indices 2 and 4. The resulting array is nums = [3,3,4,3,4].
// - Apply the second operation on the elements at indices 0, 1, and 3. The resulting array is nums = [4,4].
// - Apply the first operation on the elements at indices 0 and 1. The resulting array is nums = [].
// It can be shown that we cannot make the array empty in less than 4 operations.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for (int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int sum = 0;
        for (auto it:mp){
            if (it.second==1){
                return -1;
            }
            else{
                sum+= ceil((double)it.second/3);
            }
        }
        return sum;
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
    auto ans = ob.minOperations(nums);
    cout<<ans;
    return 0;
}