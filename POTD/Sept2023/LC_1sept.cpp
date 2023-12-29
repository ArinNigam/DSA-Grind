#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> solve(int n){ 
        vector<int>ans;
        for (int j=0;j<=n;j++){
            int cnt = 0;
            for (int i=0;i<=31;i++){
                if ((j&(1<<i))!=0){
                    cnt+=1;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

signed main()
{    
    int n;
    cin>>n;
    // vector<int>nums(n);
    // for (int i=0;i<n;i++){
    //     cin>>nums[i];
    // }
    Solution ob;
    auto ans = ob.solve(n);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}