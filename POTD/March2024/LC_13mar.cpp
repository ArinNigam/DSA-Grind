// Find the Pivot Integer (Easy)
// Given a positive integer n, find the pivot integer x such that:

// The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
// Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

// Input: n = 8
// Output: 6
// Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int sum = n*(n+1)/2;
        int cnt = 0;
        int left = 0;
        int right = n;
        while(left<=right){
            int mid = left + (right - left)/2;
            int firstSum = mid*(mid+1)/2;
            int secSum = sum-firstSum+ mid;
            if (firstSum == secSum){
                return mid;
            }
            else if (firstSum < secSum){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return -1;
    }
};

signed main()
{    
    int n;
    cin>>n;
    Solution ob;
    auto ans = ob.pivotInteger(n);
    cout<<ans;
    return 0;
}