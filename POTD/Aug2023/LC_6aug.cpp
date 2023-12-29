// Number of Music Playlists ( Hard )
// Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip.
// To avoid boredom, you will create a playlist so that:

// Every song is played at least once.
// A song can only be played again only if k other songs have been played.
// Given n, goal, and k, return the number of possible playlists that 
// you can create. Since the answer can be very large, return it modulo 109 + 7.

// n=1 goal=3 k=3
// OUTPUT = 6
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9+7;
    long long  solve (int n,int goal,int k,vector<vector<int>>&dp){
        if (n==0 && goal == 0) return 1;
        if (n==0 || goal==0) return 0;
        if (dp[n][goal]!=-1) return dp[n][goal];
        long long pick = solve(n-1,goal-1,k,dp)*n;
        long long notPick = solve(n,goal-1,k,dp)*max(n-k,0);
        return dp[n][goal] = ( pick + notPick ) % mod;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        vector<vector<int>>dp(n+1,vector<int>(goal+1,-1));
        return solve(n,goal,k,dp);
    }
};

signed main()
{    
    int n,goal,k;
    cin>>n>>goal>>k;
    Solution ob;
    auto ans = ob.numMusicPlaylists(n,goal,k);
    cout<<ans;
    return 0;
}