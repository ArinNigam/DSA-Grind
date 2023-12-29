#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];
int cnt=0;
int func(int i,int sum){
	cnt++;
	if (i==0) return 1;
	if (i==1) return 1;
	func(i-1,sum+1)+func(i-2,sum+2);
	func(i-1,sum)+func(i-2,sum+2);
	func(i-1,sum+1)+func(i-2,sum);
	func(i-1,sum)+func(i-2,sum);
}

// f(10) 
// f(8) f(9)
// f(6) f(7) f(9)
// f(4) f(5) f(7)
// f(2) f(3)
// f(0) f(1)
signed main()
{	
	int n,m;
	cin>>n>>m;
	if (m>n){
		cout<<-1;
	}
	else{
		cout<<func(n);
	}
	
	return 0;
}