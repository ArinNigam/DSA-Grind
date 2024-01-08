#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums){
        int n= nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        unordered_map<long,vector<int>>mp;
        for (int i=0;i<n;i++){
            if (!mp.count(nums[i])){
                mp[nums[i]]=vector<int>();
            }
            mp[nums[i]].push_back(i);
        }
        if (n<3) return 0;
        int sum = 0;
        for (int i=1;i<n;i++){
            int diff = nums[i+1]-nums[i];
            for (int j=i+1;j<n;j++){
                long a = 2 * nums[i]-nums[j];
                if (mp.count(a)){
                    for (auto k: mp[a]){
                        if (k<i){
                            dp[i][j] += dp[k][i] + 1;
                        }
                        else{
                            break;
                        }
                    }
                }
                sum += dp[i][j];
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
    auto ans = ob.numberOfArithmeticSlices(nums);
    cout<<ans;
    return 0;
}