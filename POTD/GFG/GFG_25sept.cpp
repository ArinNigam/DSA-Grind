// Maximum Sum Combination
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        priority_queue<pair<int,int>>pq;
        for (int i=0;i<N;i++){
            int sum = A[i] + B[N-1];
            pq.push({sum,N-1});
        }
        vector<int>ans;
        while(K--){
            auto it = pq.top();
            int sum = it.first;
            int ind = it.second;
            pq.pop();
            ans.push_back(sum);
            if (ind>=1){
                pq.push({sum-B[ind]+B[ind-1],ind-1});
            }
        }
        return ans;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums1(n),nums2(n);
    for (int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for (int i=0;i<n;i++){
        cin>>nums2[i];
    }
    Solution ob;
    auto ans = ob.maxCombinations(n,k,nums1,nums2);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}