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
    int n;
    cin>>n;
    vi v(n);
    repi(0,n){
        cin>>v[i];
    }
    if (count(all(v),v[0])==n){
        cout<<0;
        return;
    }
    unordered_map<int, int> mp;
    for (int i=0; i<n; i++) {
        if (mp.find(v[i]) != mp.end()) {
            mp[v[i]]++;
        } 
        else {
            mp[v[i]] = 1;
        }
    }
    
   
    int maxi = 0;
    for (auto it : mp) {
        // cout<<it.ff<<" "<<it.ss<<endl;
        maxi = max(maxi, it.ss);
    }
    int cnt=-1;
    for (auto it:mp){
        if(it.ss==maxi && it.ss >1){
            cnt++;
        }
    }
    if (cnt!=-1){
        cout<<(n - maxi+cnt); 
    }
    else{
        cout<<(n - maxi); 
    }
    
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
