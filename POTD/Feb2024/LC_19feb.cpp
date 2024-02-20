// Given an integrer n 
// find if the given number is a power of 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n==1){
            return true;
        }
        for (int i=1;i<31;i++){
            if ((1<<i)==n){
                return true;
            }
        }
        return false;
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
    auto ans = ob.solve(nums);
    cout<<ans;
    return 0;
}