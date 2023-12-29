// Minimum operations to remove leftmost and rightmost element and get sum = x
// Slider Window Approach
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = 0;
        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum==x){
            return nums.size();
        }
        sum = sum-x;
        int totsum = 0;
        int ans = 0;
        int i = 0,j = 0;
        while(j<nums.size()){
            totsum+=nums[j];
            while(i<j && totsum > sum){
                totsum-=nums[i];
                i++;
            }
            if (totsum == sum){
                ans = max(ans,j-i+1);
            }
            j++;
        }
        return ans == 0 ? -1 : nums.size()-ans;
    }
};

signed main()
{    
    int n,x;
    cin>>n>>x;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.minOperations(nums,x);
    cout<<ans;
    return 0;
}