//Bitwise AND of Numbers Range
// Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.
//Input: left = 5, right = 7
// Output: 4
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(right>left){
            right = (right&(right-1));
        }
        return right;
    }
};

signed main()
{    
    int left,right;
    cin>>left>>right;
    Solution ob;
    auto ans = ob.rangeBitwiseAnd(left,right);
    cout<<ans;
    return 0;
}