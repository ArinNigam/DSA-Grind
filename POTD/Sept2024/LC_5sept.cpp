// Find Missing Observations (Medium)

// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. n of the observations went missing, and you only have the observations of m rolls. Fortunately, you have also calculated the average value of the n + m rolls.
// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. You are also given the two integers mean and n.
// Return an array of length n containing the missing observations such that the average value of the n + m rolls is exactly mean. If there are multiple valid answers, return any of them. If no such array exists, return an empty array.
// The average value of a set of k numbers is the sum of the numbers divided by k.
// Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

// Input: rolls = [3,2,4,3], mean = 4, n = 2
// Output: [6,6]
// Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = accumulate(rolls.begin(),rolls.end(),0);
        int missingSum = mean * (m + n) - sum;
        
        if (missingSum > 6 * n || missingSum < n){
            return {};
        }
        int distMean = missingSum/n;
        int mod = missingSum % n;
        vector<int>ans(n,distMean);
        for(int i=0;i<mod;i++){
            ans[i]++;
        }
        return ans;
    }
};

signed main()
{    
    int m;
    cin>>m;
    vector<int>rolls(m);
    for (int i=0;i<m;i++){
        cin>>rolls[i];
    }
    int mean,n;
    cin>>mean>>n;
    Solution ob;
    auto ans = ob.missingRolls(rolls,mean,n);
    for(auto it:ans){
        cout << it << " ";
    }
    return 0;
}