// Sum of Square Numbers ( Medium )

// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.
// Example 1:

// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i=2;i<sqrt(c);i++){
            if (c%i!=0) continue;
            int expo = 0;
            while(c%i==0){
                c/=i;
                expo++;
            }
            if (i%4==3 && expo%2) return false;
        }
        return c%4!=3;
    }
};

signed main()
{   
    int c;
    cin>>c;
    Solution ob;
    auto ans = ob.judgeSquareSum(c);
    cout<<ans;
    return 0;
}