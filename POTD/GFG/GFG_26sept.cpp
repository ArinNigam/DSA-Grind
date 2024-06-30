// Four sum with O(N^2)
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for (int i=0;i<n;i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j=i+1;j<n;j++){
                if (j > i+1 && nums[j] == nums[j - 1]) continue;
                int l = j+1;
                int r = n-1;
                while(l<r){
                    long long sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum==k){
                        vector<int> temp = {nums[i],nums[j],nums[l],nums[r]};
                        ans.push_back(temp);
                        l++;
                        r--;
                        while(l<r && nums[l]==nums[l-1])l++;
                        while(l<r && nums[r]==nums[r+1])r--;
                    }
                    else if (sum < k) l++;
                    else r--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.fourSum(nums,k);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}