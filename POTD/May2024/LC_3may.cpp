// Compare Version Numbers (Medium)

// Given two version numbers, version1 and version2, compare them.

// Return the following:

// If version1 < version2, return -1.
// If version1 > version2, return 1.
// Otherwise, return 0.

// Input: version1 = "1.01", version2 = "1.001"
// Output: 0
// Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size();
        int n2 = version2.size();
        int x=0,y=0;
        for (int i=0,j=0;i<n1||j<n2;i++,j++){
            while(i<n1 && version1[i]!='.'){
                x =10*x + (version1[i++]-'0');
            }
            while(j<n2 && version2[j]!='.'){
                y =10*y + (version2[j++]-'0');
            }
            if (x<y){
                return -1;
            }
            else if (x>y){
                return 1;
            }
            
            x = 0;
            y = 0;
        }
        return 0;
    }
};

signed main()
{    
    string a,b;
    cin>>a>>b;
    Solution ob;
    auto ans = ob.compareVersion(a,b);
    cout<<ans;
    return 0;
}