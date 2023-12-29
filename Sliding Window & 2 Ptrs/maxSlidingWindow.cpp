#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int n = nums.size();
        int l = 0;
        int r = 0;
        vector<int>ans;
        while(r+k<=n){
            for (int i=l;i<k+r;i++){
                pq.push(nums[i]);
                if (pq.size()>1){
                    pq.pop();
                }
            }
            ans.push_back(pq.top());
            pq.pop();
            r++;
            l++;
        }
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
    vector<int> ans = ob.maxSlidingWindow(nums,k);
    for (auto i: ans){
        cout<<i<<" ";
    }
    return 0;
}