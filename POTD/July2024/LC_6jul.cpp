// Pass the Pillow (Easy)
// There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.

// For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
// Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.
// Input: n = 4, time = 5
// Output: 2
// Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
// After five seconds, the 2nd person is holding the pillow.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        if (time < n){
            return time+1;
        }
        else{
            if (time/(n-1)%2 == 0){
                return 1 + time%(n-1);
            }
            else{
                return n-time%(n-1);
            }
        }
    }
};

signed main()
{    
    int n,time;
    cin>>n>>time;
    Solution ob;
    auto ans = ob.passThePillow(n,time);
    cout<<ans;
    return 0;
}