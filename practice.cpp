#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    const int mod = 1e9+7;
    long long f(int n,int k){
        if (k==0) return 1;
        if (k<0 || n<=0) return 0;
        if (dp[n][k]!=-1) return dp[n][k];
        return dp[n][k] = (f(n-1,k)%mod +f(n,k-1)%mod-f(n-1,k-n)%mod)%mod;
    }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    Solution ob;
    auto ans = ob.kInversePairs(n,k);
    cout<<ans;
    return 0;
}