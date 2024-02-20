#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++){
            if (nums[i]!=i){
                return i;
            }
        }
        return n;
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
    auto ans = ob.missingNumber(nums);
    cout<<ans;
    return 0;
}