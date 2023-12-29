//  Extra Characters in a String
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        vector<int>dp(n+1,n+1);
        dp[0] = 0;

        unordered_set<string> dict(dictionary.begin(),dictionary.end());
        for (int i=1;i<=n;i++){
            dp[i] = dp[i-1] + 1;
            for (int j = 1;j<=i;j++){
                if (dict.find(s.substr(i-j,j))!=dict.end()){
                    dp[i] = min(dp[i],dp[i-j]);
                }
            }
        }
        return dp[n];
    }
};

signed main()
{   
    string s;
    cin>>s;
    int n;
    cin>>n;
    vector<string>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    auto ans = ob.minExtraChar(s,nums);
    cout<<ans;
    return 0;
}