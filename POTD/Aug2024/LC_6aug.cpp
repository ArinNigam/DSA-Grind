// Minimum Number of Pushes to Type Word II (Medium)

// You are given a string word containing lowercase English letters.
// Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", two times to type "b", and three times to type "c" .
// It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times the keys will be pushed to type the string word.
// Return the minimum number of pushes needed to type word after remapping the keys.
// An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

// Input: word = "abcde"
// Output: 5
// Explanation: The remapped keypad given in the image provides the minimum cost.
// "a" -> one push on key 2
// "b" -> one push on key 3
// "c" -> one push on key 4
// "d" -> one push on key 5
// "e" -> one push on key 6
// Total cost is 1 + 1 + 1 + 1 + 1 = 5.
// It can be shown that no other mapping can provide a lower cost.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        vector<int>vp(26);
        int cnt = 0;
        for(auto it:word){
            vp[it-'a']++;
        }
        sort(vp.rbegin(),vp.rend());
        for(int i=0;i<26;i++){
            if (i>=0 && i<8){
                cnt+=1*vp[i];
            }
            else if (i>=8 && i<16){
                cnt+=2*vp[i];
            }
            else if (i>=15 && i<24){
                cnt+=3*vp[i];
            }
            else{
                cnt+=4*vp[i];
            }
        }
        return cnt;
    }
};

signed main()
{    
    string s;
    cin>>s;
    Solution ob;
    auto ans = ob.minimumPushes(s);
    cout<<ans;
    return 0;
}