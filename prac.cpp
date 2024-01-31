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
    ll a,b,r;
    cin>>a>>b>>r;
    if (b>a){
        swap(a,b);
    }
    ll mini = abs(a-b);
    ll ans = mini;
    // cout<<(1LL<<63)-1<<" ";
    ll k =0;
    repn(63,0){
        cout<<((b>>i)&1);
        if (((b>>i)&1) ==0 && ((a>>i)&1)==1){
            if (k+(1LL<<i)<=r){
                if (mini>=1LL<<(i+1)){
                    k+=(1LL<<i);
                    mini -= (1LL<<(i+1));
                }
               
            }
         
        }
    }
    cout<<min(mini,ans);
    
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
