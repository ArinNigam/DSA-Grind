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

ll bs(ll ind,vector<ll>&v,ll n){
    ll low = 0;
    ll high = ind;
    ll ans = ind; 
    while(low<=high){
        ll mid = low + (high-low)/2;
        if (v[ind]-v[mid]<n){
            ans = mid;
            high = mid-1;
           
        }
        else{
            low = mid+1;
        }
        
    }
    return ind-ans+1;
}
void solve()
{
    ll n;
    cin>>n;
    vl v(n);
    repi(0,n){
        cin>>v[i];
    }
    sort(all(v));
    vl x;
    x.push_back(v[0]);
    repi(1,n){
        if (x.back()!=v[i]){
             x.push_back(v[i]);
        }
    }
    
    ll m = x.size();

    ll ans = 0;
    repi(0,m){
        ans = max(ans,bs(i,x,n));
    }
    
    cout<<ans;
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
