// Fenwick Tree or Binary Indexed Tree

#include<bits/stdc++.h>
using namespace std;

class FenwickTree {
    vector<int> bit;
    int n;
public:
    FenwickTree(int size) : n(size), bit(size + 1, 0) {}

    void update(int i, int x) {
        while (i <= n) {
            bit[i] += x;
            i += (i & (-i));
        }
    }

    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= (i & (-i));
        }
        return sum;
    }

    int query(int left, int right) {
        return query(right) - query(left - 1);
    }
};

class Solution {
public:
  int solve(vector<int>& nums,vector<vector<int>>&queries){
      int N = nums.size();
      FenwickTree tree(N);
      
      // 1 Based indexing is necessary
      // Otherwise there is an infinite loop
      for(int i=1;i<=N;i++){
          tree.update(i,nums[i-1]);
      }
      int q = queries.size();
      for(int i=0;i<q;i++){
          int l = queries[i][0];
          int r = queries[i][1];
          cout<<tree.query(l,r)<<" "; 
      }
      return 0;
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
  int m;
  cin>>m;
  vector<vector<int>>queries(m,vector<int>(2));
  for(int i=0;i<m;i++){
      cin>>queries[i][0];
      cin>>queries[i][1];
  }
  Solution ob;
  auto ans = ob.solve(nums,queries);
  return 0;
}