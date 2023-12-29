//Remove coloured pieces if both neighbours same color
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char,int>mp;
        int i =0;
        while(i<colors.size()){
            char x = colors[i];
            int j = i;
            while(j!=colors.size() && colors[j]==x){
                j++;
            }
            mp[x] += max(abs(i-j)-2,0);
            i=j;
        }
        if (mp['A']>mp['B']){
            return true;
        }
        return false;
    }
};

signed main()
{   
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.winnerOfGame(s);
    cout<<ans;
    return 0;
}