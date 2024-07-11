// Given a number n, print all primes smaller than or equal to n. 
// It is also given that n is a small number

// TC - O(N*log(logN))
// SC - O(N)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sieveOfEratosthenes(int n){
        vector<bool>primes(n+1,true);
        primes[0] = false;
        primes[1] = false;
        for(int i=2;i*i<=n;i++)
        {
            if (primes[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    primes[j] = false;
                }
            }
        }
        vector<int> ans;
        for(int i=2;i<=n;i++){
            if (primes[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

signed main()
{    
    int n;
    cin>>n;
    
    Solution ob;
    auto ans = ob.sieveOfEratosthenes(n);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}