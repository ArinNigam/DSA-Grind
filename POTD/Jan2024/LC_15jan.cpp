// Find Players With Zero or One Losses (Medium)
// Return a list answer of size 2 where:

// answer[0] is a list of all players that have not lost any matches.
// answer[1] is a list of all players that have lost exactly one match.

// You should only consider the players that have played at least one match.
// The testcases will be generated such that no two matches will have the same outcome.

// Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
// Output: [[1,2,10],[4,5,7,8]]
// Explanation:
// Players 1, 2, and 10 have not lost any matches.
// Players 4, 5, 7, and 8 each have lost one match.
// Players 3, 6, and 9 each have lost two matches.
// Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>ans(2);
        map<int,vector<int>> wins;
        map<int,vector<int>> loss;
        for (int i=0;i<n;i++){
            wins[nums[i][0]].push_back(nums[i][1]);
            loss[nums[i][1]].push_back(nums[i][0]);
        }
        for (auto it:loss){
            if (it.second.size()==1){
                ans[1].push_back(it.first);
            }
            if (wins.find(it.first)!=wins.end()){
                wins.erase(it.first);
            }
        }
        for (auto it:wins){
            ans[0].push_back(it.first);
        }
        return ans;
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>nums(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>nums[i][j];
        }
    }
    Solution ob;
    auto ans = ob.findWinners(nums);
    for (auto i:ans){
      for (auto j:i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
    return 0;
}