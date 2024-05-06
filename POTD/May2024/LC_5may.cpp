// Boats to Save People (Medium)

// You are given an array people where people[i] is the weight of the 
// ith person, and an infinite number of boats where each boat can carry
//  a maximum weight of limit. Each boat carries at most two people at 
//  the same time, provided the sum of the weight of those people is at
//   most limit.

// Return the minimum number of boats to carry every given person.

// Example 1:

// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(),people.end());
        
        int l = 0;
        int r = n-1;
        
        int cnt = 0;
        while(l<=r){
            int sum = people[l] + people[r];
            
            if (sum<=limit){
                l++;
                r--;
                cnt++;
            }
            else{
                cnt++;
                r--;
            }
        }
        return cnt;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    int limit;
    cin>>limit;
    Solution ob;
    auto ans = ob.numRescueBoats(nums,limit);
    cout<<ans;
    return 0;
}