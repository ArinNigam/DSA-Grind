// Fraction Addition and Subtraction (Medium)

// Given a string expression representing an expression of fraction addition and subtraction, return the calculation result in string format.
// The final result should be an irreducible fraction. If your final result is an integer, change it to the format of a fraction that has a denominator 1. So in this case, 2 should be converted to 2/1.

// Example 1:
// Input: expression = "-1/2+1/2"
// Output: "0/1"

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionAddition(string exp)
    {
        int n = exp.size();
        int numerator = 0;
        int denominator = 1;
        for (int i = 0; i < n;)
        {
            int sign = 1;
            if (exp[i] == '+' || exp[i] == '-')
            {
                if (exp[i] == '-')
                {
                    sign = -1;
                }
                i++;
            }

            int num = 0;
            while (i < n && isdigit(exp[i]))
            {
                num = num * 10 + exp[i] - '0';
                i++;
            }
            num *= sign;

            i++;

            int den = 0;
            while (i < n && isdigit(exp[i]))
            {
                den = den * 10 + exp[i] - '0';
                i++;
            }

            numerator = numerator * den + num * denominator;
            denominator *= den;

            int gcdVal = __gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }
        return to_string(numerator) + '/' + to_string(denominator);
    }
};

signed main()
{
    string s;
    cin >> s;
    Solution ob;
    auto ans = ob.fractionAddition(s);
    cout << ans;
    return 0;
}