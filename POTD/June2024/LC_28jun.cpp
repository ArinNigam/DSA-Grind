// Maximum Total Importance of Roads (Medium)

// You are given an integer n denoting the number of cities in a country. The cities are numbered from 0 to n - 1.
// You are also given a 2D integer array roads where roads[i] = [ai, bi] denotes that there exists a bidirectional road connecting cities ai and bi.
// You need to assign each city with an integer value from 1 to n, where each value can only be used once. The importance of a road is then defined as the sum of the values of the two cities it connects.
// Return the maximum total importance of all roads possible after assigning the values optimally.

// Input: n = 5, roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
// Output: 43
// Explanation: The figure above shows the country and the assigned values of [2,4,5,3,1].
// - The road (0,1) has an importance of 2 + 4 = 6.
// - The road (1,2) has an importance of 4 + 5 = 9.
// - The road (2,3) has an importance of 5 + 3 = 8.
// - The road (0,2) has an importance of 2 + 5 = 7.
// - The road (1,3) has an importance of 4 + 3 = 7.
// - The road (2,4) has an importance of 5 + 1 = 6.
// The total importance of all roads is 6 + 9 + 8 + 7 + 7 + 6 = 43.
// It can be shown that we cannot obtain a greater total importance than 43.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<pair<int,int>>&v1,vector<pair<int,int>>&v2){
        return v1.size() < v2.size();
    }
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<vector<pair<int,int>>>adj(n);
        for(auto road:roads){
            adj[road[0]].push_back({road[1],road[0]});
            adj[road[1]].push_back({road[0],road[1]});
        }
        sort(adj.begin(),adj.end(),cmp);
        unordered_map<int,int>mp;
        
        for(int i=1;i<=n;i++){
            if (adj[i-1].size()!=0){
                mp[adj[i-1][0].second] = i;
            }
        }
        int sum = 0;
        for(auto it:roads){
            sum+=mp[it[0]];
            sum+=mp[it[1]];
        }
        return sum;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>nums(m,vector<int>(2));
    for (int i=0;i<m;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.maximumImportance(n,nums);
    cout<<ans;
    return 0;
}