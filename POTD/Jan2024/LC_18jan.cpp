// Climbing Stairs (Easy)
// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Hint: Fibonaci
#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define repi(a,b) for (int i=a;i<b;i++)
#define repj(a,b) for (int j=a;j<b;j++)
#define repn(a,b) for (int i=a;i>=b;i--)

#define all(v) v.begin(),v.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define mii map<int,int>
#define ff first
#define ss second

const int N=1e5+5;


void solve()
{
    ll a,b;
    cin>>a>>b;
    ll diff = abs(a-b);
    ll low = 0;
    ll high = sqrt(diff);
    high*=2;
    ll mid = 0;
    ll sum = 0;
    while(high!=low){
        mid = (high+low)/2;
        sum = mid*(mid+1)/2;
        if (sum>=diff){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
   
    if (diff%2==0){
        if (low%4==1){
            low+=2;
        }
        else if (low%4==2){
            low++;
        }
    }
    
    if (diff%2==1){
        if (low%4==3){
            low+=2;
        }
        else if (low%4==0){
            low++;
        }
    }
    cout<<low;
    
}

signed main()
{    
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
        cout<<endl;
    }
    return 0;    
}
