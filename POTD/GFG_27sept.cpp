// minimise | sum - x |
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    vector<int> printClosest(vector<int> arr, vector<int> brr, int n, int m, int x) {
        //code here
        int minDiff = INT_MAX;
        int diff = 0;
        int i = 0;
        int j = m-1;
        int sum = 0;
        vector<int>ans;
        while(i<n && j>=0){
            sum = arr[i] + brr[j];
            diff = abs(sum-x);
            if(diff< minDiff){
                ans.clear();
                ans.push_back(arr[i]);
                ans.push_back(brr[j]);
                minDiff = diff;
            }
            if (sum>x) j--;
            else i++;
        }
        return ans;
    }
};
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),brr(m);
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        cin>>brr[i];
    }
    int x;
    cin>>x;
    
    Solution ob;
    auto ans = ob.printClosest(arr,brr,n,m,x);

    return 0;
}