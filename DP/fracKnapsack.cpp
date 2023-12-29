// 0/1 Frac Knapsack
#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

bool compare(pair<ll,ll>p1,pair<ll,ll>p2){
  if (p1.second == p2.second){
    return p1.first>p2.first;
  }
  return p1.second<p2.second;
}
signed main()
{  
  int w,n;
  cin>>w>>n;
  vector<pair<ll,ll>>nums(n);  
  for (int i=0;i<n;i++){
    cin>>nums[i].first;
  }
  for (int i=0;i<n;i++){
    cin>>nums[i].second;
  }
  sort(nums.begin(),nums.end(),compare);
  ll ans = 0;
  ll pos = 0;
  for (int i=0;i<n;i++){
    if (nums[i].first>=w){
      ans+= w * nums[i].second;
      pos = i+1;
      break;
    }
    else{
      ans+=nums[i].first * nums[i].second;
      w-=nums[i].first;
    }
  }
  cout<<ans<<' '<<pos;
  return 0;
}