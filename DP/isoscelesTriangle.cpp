// Isoscele Triangle 
// Bottom Up aproach
#include<bits/stdc++.h>
using namespace std;
  
signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>mat[i][j];
        }
    }
    
    vector<vector<int>>dp1(n,vector<int>(m,0));
    vector<vector<int>>dp2(n,vector<int>(m,0));
    for(int i=n-1;i>=0;i--){
        for (int j=m-1;j>=0;j--){
            if(mat[i][j]==0){
                dp1[i][j]=1;
            }
            // if point lies in (first or last column or last row)
            if (i==n-1 || j==0 || j==m-1) continue;
            
            else if (mat[i][j]==0){
                dp1[i][j]= min({dp1[i+1][j-1],dp1[i+1][j],dp1[i+1][j+1]}) +1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(mat[i][j]==0){
                dp2[i][j]=1;
            }
            // if point lies in (first or last column or first row)
            if (i==0 || j==0 || j==m-1) continue;
            
            else if (mat[i][j]==0){
                dp2[i][j]= min({dp2[i-1][j-1],dp2[i-1][j],dp1[i-1][j+1]}) +1;
            }
        }
    }
    int ans=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(mat[i][j]==0){
                ans+=(dp1[i][j]+dp2[i][j]-2);
            }
        }
    }
    cout<<ans;
    return 0;
}