// Maximum Points You Can Obtain from Cards
// INPUT
// 7 3
// 1 2 3 4 5 6 1
// OUTPUT
// 12
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum=0;
        for (int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int curr = sum;
        for (int i=k-1;i>=0;i--){
            curr-=cardPoints[i];
            curr+=cardPoints[n-k+i];
            sum = max(sum,curr);
        }
        return sum;
    }
};

signed main()
{    
    int n,k;
    cin>>n>>k;
    vector<int>nums(n);
    for (int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    int ans = ob.maxScore(nums,k);
    cout<<ans;
    return 0;
}