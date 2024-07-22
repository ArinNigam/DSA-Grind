#include<bits/stdc++.h>
using namespace std;

// Fast Exponentiation
class Solution {
public:
    const long long mod = 1e9 + 7;
    int solve(int n){
        long long ans = 1;
        long long x = 2;
        
        while(n>0){
            if (n & 1){
                ans = (ans*x)%mod;
            }
            x = ((x % mod) * (x % mod)) % mod;
            n >>=1;
        }
        return ans;
    }

    int solve(int a,int n){
        if (n == 0){
            return 1;
        } 
        if (n==1){
            return a;
        }
        int x = solve(a,n/2);
        if (n%2 == 0){
            return ((x % mod) * (x % mod)) % mod;
        }
        else{
            return ((x % mod) * a * (x % mod)) % mod;
        }
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.solve(2,n);
    cout<<ans;
    return 0;
}