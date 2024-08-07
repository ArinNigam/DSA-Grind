// Freedom Trail (Hard)

// In the video game Fallout 4, the quest "Road to Freedom" requires players to reach a metal dial called the "Freedom Trail Ring" and use the dial to spell a specific keyword to open the door.
// Given a string ring that represents the code engraved on the outer ring and another string key that represents the keyword that needs to be spelled, return the minimum number of steps to spell all the characters in the keyword.
// Initially, the first character of the ring is aligned at the "12:00" direction. You should spell all the characters in key one by one by rotating ring clockwise or anticlockwise to make each character of the string key aligned at the "12:00" direction and then by pressing the center button.
// At the stage of rotating the ring to spell the key character key[i]:

// You can rotate the ring clockwise or anticlockwise by one place, which counts as one step. The final purpose of the rotation is to align one of ring's characters at the "12:00" direction, where this character must equal key[i].
// If the character key[i] has been aligned at the "12:00" direction, press the center button to spell, which also counts as one step. After the pressing, you could begin to spell the next character in the key (next stage). Otherwise, you have finished all the spelling.

// Input: ring = "godding", key = "gd"
// Output: 4
// Explanation:
// For the first key character 'g', since it is already in place, we just need 1 step to spell this character. 
// For the second key character 'd', we need to rotate the ring "godding" anticlockwise by two steps to make it become "ddinggo".
// Also, we need 1 more step for spelling.
// So the final output is 4. 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int ind,int pos,unordered_map<char,vector<int>>&mp, string &key,string &ring,vector<vector<int>>&dp){
        if (ind==key.size()){
            return 0;
        }
        if (dp[ind][pos]!=-1){
            return dp[ind][pos];
        }
        int min_steps = INT_MAX;
        for (int i : mp[key[ind]]) {
            int steps;
            if (i >= pos) {
                steps = min(i - pos, static_cast<int>(pos + ring.size()) - i);
            } else {
                steps = min(pos - i, static_cast<int>(i + ring.size()) - pos);
            }
            int next_steps = solve(ind + 1, i, mp, key, ring, dp);
            min_steps = min(min_steps, steps + next_steps);
        }
        dp[ind][pos] = min_steps + 1;
        return min_steps + 1;
    }
    int findRotateSteps(string ring, string key) {
        int m = key.size();
        int n = ring.size();
        unordered_map<char,vector<int>>mp;
        for (int i=0;i<n;i++){
            mp[ring[i]].push_back(i);
        }
        vector<vector<int>>dp(m,vector<int>(n,-1));
        
        return solve(0, 0, mp, key, ring, dp);
    }
};

signed main()
{    
    
    string ring,key;
    cin>>ring>>key;
    Solution ob;
    auto ans = ob.findRotateSteps(ring,key);
    cout<<ans;
    return 0;
}