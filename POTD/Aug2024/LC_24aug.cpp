// Find the Closest Palindrome
// Given a string n representing an integer, you need to find the closest palindrome to it. If there are multiple answers, return the smallest one.
// The closest is defined as the absolute difference minimized between two integers.

// Example 1:
// Input: n = "123"
// Output: "121"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long convert(long long& num) {
        string s = to_string(num);
        int n = s.length();
        int l = n/2;
        int r = (n - 1)/2;
        while (r >= 0){
            s[l++] = s[r--];
        }
        return stoll(s);
    }
   
    long long nextPalindrome(long long num) {
        long long l = 0;
        long long r = num;
        long long ans = INT_MIN;
        while (l <= r) {
            long long mid = l + (r - l)/2;
            long long palin = convert(mid);
            if (palin < num) {
                ans = palin;
                l = mid + 1;
            } 
            else {
                r = mid - 1;
            }
        }
        return ans;
    }

    long long previousPalindrome(long long num) {
        long long l = num;
        long long r = 1e18;
        long long ans = INT_MIN;
        while (l <= r) {
            long long mid = l + (r - l)/2;
            long long palin = convert(mid);
            if (palin > num) {
                ans = palin;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return ans;
    }
    string nearestPalindromic(string n) {
        int len = n.size();
        long long num = stoll(n);
        long long a = nextPalindrome(num);
        long long b = previousPalindrome(num);
        if (abs(a - num) <= abs(b - num)) return to_string(a);
        return to_string(b);
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.nearestPalindromic(s);
    cout<<ans;
    return 0;
}