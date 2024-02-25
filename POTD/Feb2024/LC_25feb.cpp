// Greatest Common Divisor Traversal (Hard)
// You are given a 0-indexed integer array nums, and you are allowed to traverse between its indices. You can traverse between index i and index j, i != j, if and only if gcd(nums[i], nums[j]) > 1, where gcd is the greatest common divisor.
// Your task is to determine if for every pair of indices i and j in nums, where i < j, there exists a sequence of traversals that can take us from i to j.

// Return true if it is possible to traverse between all such pairs of indices, or false otherwise.

// Input: nums = [2,3,6]
// Output: true
// Explanation: In this example, there are 3 possible pairs of indices: (0, 1), (0, 2), and (1, 2).
// To go from index 0 to index 1, we can use the sequence of traversals 0 -> 2 -> 1, where we move from index 0 to index 2 because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1, and then move from index 2 to index 1 because gcd(nums[2], nums[1]) = gcd(6, 3) = 3 > 1.
// To go from index 0 to index 2, we can just go directly because gcd(nums[0], nums[2]) = gcd(2, 6) = 2 > 1. Likewise, to go from index 1 to index 2, we can just go directly because gcd(nums[1], nums[2]) = gcd(3, 6) = 3 > 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MAXI = 1e5 + 100;
    vector<int> parent, size; 
    int find(int node){
        if (node == parent[node]){
            return node;
        }
        return parent[node] = find(parent[node]);
    }
    void unionBySize(int u,int v){
        int ulp_u = find(u);
        int ulp_v = find(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]){
            swap(size[ulp_u],size[ulp_v]);
        }
        size[ulp_u]+=size[ulp_v];
        size[ulp_v]=0;
        parent[ulp_v] = parent[ulp_u];
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        parent.resize(MAXI);
        size.resize(MAXI);
        if (n==1){
            return true;
        }
        map<int,int>mp;
        for (auto it:nums){
            mp[it]++;
            if (it==1){
                return false;
            }
        }
        
        vector<int>sieve(MAXI);
        for (int i=1;i<MAXI;i++){
            sieve[i]=i;
            if (mp.find(i)==mp.end()){
                size[i] = 0;
            }
            else{
                size[i] += mp[i];
            }
            parent[i] = i;
        }
        
        for(int i=2;i<MAXI;i++){
            if(sieve[i]==i){
                for(int j=i+i;j<MAXI;j+=i){
                    sieve[j]=i;
                }
            }
        }
        
        for(auto x:nums){
            map<int,int>mp2;
            int val=x;
            while(x>1){
                mp2[sieve[x]]++;
                x/=sieve[x];
            }

            for(auto it:mp2){
                int value=it.first;
                unionBySize(val,value);
            }
        }

        int cnt = 0;
        
        for (int i=2;i<MAXI;i++){
            if (parent[i] && size[i]>0){
                cnt++;
            }
        }
        
        return cnt==1;
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
    Solution ob;
    auto ans = ob.canTraverseAllPairs(nums);
    cout<<ans;
    return 0;
}


