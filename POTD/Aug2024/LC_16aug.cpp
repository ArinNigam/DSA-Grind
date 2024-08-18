// Maximum Distance in Arrays (Medium)

// You are given m arrays, where each array is sorted in ascending order.
// You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.
// Return the maximum distance.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size();
        int maxi = -10001;
        int mini = 10001;
        int ans = 0;
        for(int i=0;i<n;i++){
            int m = arrays[i].size();
            ans = max({ans,maxi-arrays[i][0],arrays[i][m-1] - mini});
            maxi = max(maxi,arrays[i][m-1]);
            mini = min(mini,arrays[i][0]);
        }
        return ans;
    }
};

signed main()
{  
  int n;
  cin>>n;
  vector<vector<int>>nums{{1,2,3},{4,5},{1,2,3}};
  
  Solution ob;
  auto ans = ob.maxDistance(nums);
  cout<<ans;
  return 0;
}