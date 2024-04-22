// Open the Lock (Medium)

// You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.
// The lock initially starts at '0000', a string representing the state of the 4 wheels.
// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, the wheels of the lock will stop turning and you will be unable to open it.
// Given a target representing the value of the wheels that will unlock the lock, return the minimum total number of turns required to open the lock, or -1 if it is impossible.

// Input: deadends = ["0201","0101","0102","1212","2002"], target = "0202"
// Output: 6
// Explanation: 
// A sequence of valid moves would be "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".
// Note that a sequence like "0000" -> "0001" -> "0002" -> "0102" -> "0202" would be invalid,
// because the wheels of the lock become stuck after the display becomes the dead end "0102".

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(),deadends.end());
        if (st.count("0000")){
            return -1;
        }

        queue<pair<string,int>>q;
        unordered_set<string>vis;
        vis.insert("0000");
        q.push({"0000",0});

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string curr = it.first;
            int moves = it.second;

            if (curr== target){
                return moves;
            }

            for (int i=0;i<4;i++){
                for (int del: {-1,1}){
                    int newDig = (curr[i] - '0' + del + 10)%10;
                    string newComb = curr;
                    newComb[i] = '0' + newDig;
                    if (vis.find(newComb)==vis.end() && st.find(newComb)==st.end()){
                    vis.insert(newComb);
                    q.push({newComb,moves+1});
                } 
                }
                
            }
        }
        return -1;

    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<string>deadends(n);
    for (int i=0;i<n;i++){
        cin>>deadends[i];
    }
    string target;
    cin>>target;
    Solution ob;
    auto ans = ob.openLock(deadends,target);
    cout<<ans;
    return 0;
}