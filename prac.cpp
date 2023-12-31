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
    ll sum = 0;
    set<ll>st={0};
    bool flag = 0;
    repi(0,n){
        cin>>v[i];
        if (i%2){
            sum+=v[i]*-1;
        }
        else{
            sum+=v[i];
        }
        
        if (st.count(sum)){
            flag = 1;
        }
        st.insert(sum);
    }
    cout<<((flag==1) ? "YES" : "NO");
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
