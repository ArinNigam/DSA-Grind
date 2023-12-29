//Minimum Replacements to Sort the Array
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums){
        int n = nums.size();
        int mini = INT_MAX;
        long long cnt = 0;
        for (int i=n-1;i>=0;i--){
            if (mini > nums[i]){
                mini = nums[i];
            }
            else{
                int t= nums[i]/mini;
                if (nums[i]%mini == 1) t++;
                mini = nums[i]/t;
                cnt += t-1;
            }  
        }
        return cnt;
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
    auto ans = ob.minimumReplacement(nums);
    cout<<ans;
    return 0;
}