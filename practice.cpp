#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        for (char a = '1';a<='9';a++){
            string s="";
            for (char b=a;b<='9';b++){
                s+=b;
                if (stoi(s)>=low && stoi(s)<=high){
                    ans.push_back(stoi(s));
                }
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
signed main()
{    
    int low,high;
    cin>>low>>high;
    Solution ob;
    auto ans = ob.sequentialDigits(low,high);
    for (auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}