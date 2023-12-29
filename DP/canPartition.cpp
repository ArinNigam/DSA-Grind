#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool solve(int ind,int sum,int arr[],int N){
        if (ind<0){
            return 0;
        }
        if (sum==0) return 1;
        bool pick= 0;
        if (arr[ind]<=sum){
            pick = solve(ind-1,sum-arr[ind],arr,N);
        }
        bool notPick = solve(ind-1,sum,arr,N);
        return pick | notPick;
    }
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i=0;i<N;i++){
            sum+=arr[i];
        }
        if (sum%2) return 0;
        sum/=2;
        return solve(N-1,sum,arr,N)==1 ? 1 : 0;
        
    }
};

signed main()
{    
    int n;
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    Solution ob;
    auto ans = ob.equalPartition(n,arr);
    cout<<ans;
    return 0;
}