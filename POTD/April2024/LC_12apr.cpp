// Trapping Rain Water (Hard)

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        int prefix[n];
        int suffix[n];
        
        prefix[0] = height[0];
        suffix[n-1] = height[n-1];
        int ans = 0;
        for (int i=1;i<n;i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }
        
        for (int i=n-2;i>=0;i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }
        
        for(int i=0;i<n;i++){
            ans+= min(prefix[i],suffix[i]) - height[i];
        }
        return ans;
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
    auto ans = ob.trap(nums);
    cout<<ans;
    return 0;
}