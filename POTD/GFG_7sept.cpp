// Minimum Multiplications to reach End
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int mod = 100000;
    int solve(int ind,int prod,vector<int>&arr,int end){
        if (ind < 0) return 0;
        if (prod == end){
            return 1;
        }
        int pick = solve(ind-1,(prod*arr[ind])%mod,arr,end);
        int notPick = solve(ind-1,prod,arr,end);
        return pick + notPick;
    }
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        queue<pair<int,int>>q;
        vector<int>dist(mod,1e8);
        q.push({start,0});
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int step = it.second;
            q.pop();
            if (node==end) return step;
            
            for (auto it: arr){
                int y = (node*it)%mod;
                if (1 + step < dist[y]){
                    dist[y] = 1 + step;
                    q.push({y,step+1});
                }
            }
        }
        return -1;
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
    int start,end;
    cin>>start>>end;
    Solution ob;
    auto ans = ob.minimumMultiplications(nums,start,end);
    cout<<ans;
    return 0;
}