// Find Polygon With the Largest Perimeter (Medium)
// You are given an array of positive integers nums of length n.
// A polygon is a closed plane figure that has at least 3 sides. The longest side of a polygon is smaller than the sum of its other sides.
// Conversely, if you have k (k >= 3) positive real numbers a1, a2, a3, ..., ak where a1 <= a2 <= a3 <= ... <= ak and a1 + a2 + a3 + ... + ak-1 > ak, then there always exists a polygon with k sides whose lengths are a1, a2, a3, ..., ak.

// Input: nums = [5,5,5]
// Output: 15
// Explanation: The only possible polygon that can be made from nums has 3 sides: 5, 5, and 5. The perimeter is 5 + 5 + 5 = 15.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        for (int i=n-1;i>=2;i--){
            sum-=nums[i];
            if (sum > nums[i]){
                return sum + nums[i];
            }
        }
        return -1;
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
    auto ans = ob.largestPerimeter(nums);
    cout<<ans;
    return 0;
}