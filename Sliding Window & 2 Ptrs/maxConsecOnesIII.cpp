// Max Consecutive Ones III

// INPUT
// 11 2
// 1 1 1 0 0 0 1 1 1 1 0

// OUTPUT
// 6
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0;    
        while(j<n){
            if (nums[j]==0){
                k--;
            }
            if (k<0){
                if (nums[i]==0){
                    k++;
                }
                i++;
            }
            j++;
        }
        return j-i;
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
    int ans = ob.longestOnes(nums,k);
    cout<<ans;
    return 0;
}
