//String Compression II
// s = aaabcccd
// a3bc3d
// k = 2
// OUTPUT = a3c3

// aabbaa
// k = 2
// bbaa = b2a2
// abaa = aba2
// aaaa = a4
// aaba = a2ba
// aabb = a2b2
// OUTPUT = a4

// aaaaaaaaaaa
// k = 0
// OUTPUT = a11

// -------------------------------

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,1000));
        dp[0][0] = 0;
        
        for ( int i =1; i<=n;i++ ){
            for (int j =0; j<=k;j++){
                int cntChar = 0;
                int delChar = 0;
                
                for (int t=i; t>=1 ; t--){
                    if (s[t-1]==s[i-1]){
                        cntChar++;
                    }
                    else{
                        delChar++;
                    }
                    
                    if (j>=delChar){
                        int temp = 0;
                        if (cntChar >= 100){
                            temp = 3;
                        }
                        else if (cntChar >=10){
                            temp = 2;
                        }
                        else if( cntChar >=2){
                            temp= 1;
                        }
                        
                        dp[i][j] = min(dp[i][j],dp[t-1][j-delChar]+1+ temp);
                    }
                }
                if (j>0){
                    dp[i][j] = min(dp[i][j],dp[i-1][j-1]);
                }
            }
        }
        return dp[n][k];   
    }
};
signed main()
{    
    string s;
    cin>>s;
    int k;
    cin>>k; 
    Solution ob;
    auto ans = ob.getLengthOfOptimalCompression(s,k);
    cout<<ans;
    return 0;
}