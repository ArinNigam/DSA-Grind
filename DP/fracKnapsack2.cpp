// 21 4
// 3 3 4 15
// 20 10 5 4 

// task - Minimise the cost

#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct fuel{
    ll price;
    ll weight;
};

bool cmp(fuel f1,fuel f2){
    if (f1.price == f2.price){
        return f1.weight > f2.weight;
    }
    return f1.price < f2.price;
}
signed main()
{    
    int W,N;
    cin>>W>>N;
    vector<fuel>v(N);
    for (int i=0;i<N;i++){
        cin>>v[i].weight;
    }
    for (int i=0;i<N;i++){
        cin>>v[i].price;
    }
    
    sort(v.begin(), v.end(),cmp);
    for (auto i:v){
      cout<<i.price<<" "<<i.weight;
      cout<<endl;
    }
    ll pos=0;
    ll cost=0;
    for (int i=0;i<N;i++){
        if(v[i].weight>=W){
            cost+= W * v[i].price;
            pos = i+1;
            break;
        }
        else{
            cost+= (v[i].price * v[i].weight);
            W-=v[i].weight;
        }
    }
    
    cout<<cost<<" "<<pos;
    return 0;
}