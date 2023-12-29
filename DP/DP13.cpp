#include <bits/stdc++.h>
using namespace std;
 
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pi pair < int, int >
 
const int N = 3e5 + 7;
const int mod = 1e9 + 7;
 
ll dp[N][30];
int A, B;
 
ll top_down(int stair, int triple){
    if (stair == 0)
        return 1;
    if (stair < 0)
        return 0;
    if (dp[stair][triple])
        return dp[stair][triple];
    if (triple)
        dp[stair][triple] = top_down(stair - 3, triple - 1);
    dp[stair][triple] += top_down(stair - 1, triple) + top_down(stair - 2, triple);
    return dp[stair][triple] % mod;
}
 
int main(){
    scanf("%d%d", &A, &B);
    printf("%lld", top_down(A, B));
}
