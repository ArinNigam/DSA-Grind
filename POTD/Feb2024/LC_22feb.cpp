// Find the Town Judge (Easy)
// In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// 1. The town judge trusts nobody.
// 2. Everybody (except for the town judge) trusts the town judge.
// 3. There is exactly one person that satisfies properties 1 and 2.

// You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi. If a trust relationship does not exist in trust array, then such a trust relationship does not exist.

// Input: n = 3, trust = [[1,3],[2,3]]
// Output: 3

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>adj1(n+1);
        vector<vector<int>>adj2(n+1);
        for (int i=0;i<trust.size();i++){
            adj1[trust[i][0]].push_back(trust[i][1]);
            adj2[trust[i][1]].push_back(trust[i][0]);
        }
        for (int i=1;i<=n;i++){
            if (adj1[i].size()==0 && adj2[i].size()==n-1){
                return i;
            }
        }
        return -1;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findJudge(n,nums);
    cout<<ans;
    return 0;
}