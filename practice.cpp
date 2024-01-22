#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n+1,0);
        for (int i=0;i<n;i++){
            temp[nums[i]]++;
        }
        vector<int>ans(2,0);
        for (int i=1;i<=n;i++){
            if (temp[i]==2){
                ans[0]=i;
            }
            if (temp[i]==0){
                ans[1]=i;
            }
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
    auto ans = ob.findErrorNums(nums);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}