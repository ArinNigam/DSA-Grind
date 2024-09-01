// Number Complement (Easy)

// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int cnt = 0;
        int n = num;
        int i = 0;
        while (num > 0)
        {
            if (!(n & (1 << i)))
            {
                cnt += (1 << i);
            }
            num = num >> 1;
            i++;
        }
        return cnt;
    }
};

signed main()
{
    int n;
    cin >> n;
    Solution ob;
    auto ans = ob.findComplement(n);
    cout << ans;
    return 0;
}