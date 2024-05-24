// Maximum Score Words Formed by Letters (Hard)

// Given a list of words, list of  single letters (might be repeating) and score of every character.
// Return the maximum score of any valid set of words formed by using the given letters (words[i] cannot be used two or more times).
// It is not necessary to use all characters in letters and each letter can only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by score[0], score[1], ... , score[25] respectively.

// Input: 
// words = ["dog","cat","dad","good"],
// letters = ["a","a","c","d","d","d","g","o","o"],
// score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]

// Output: 23


// Explanation:
// Score  a=1, c=9, d=5, g=3, o=2
// Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with a score of 23.
// Words "dad" and "dog" only get a score of 21.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int ind,int temp,vector<string>&words,vector<int>&score,unordered_map<char,int>&freq,unordered_map<char,int>cnt,int &ans){
        for (char i = 'a';i<='z';i++){
            if (freq[i] > cnt[i]) return;
        }
        
        ans = max(ans,temp);
        
        for (int i=ind;i<words.size();i++){
            
            for (auto it: words[i]){
                freq[it]++;
                temp+=score[it-'a'];
            }
            
            solve(i+1,temp,words,score,freq,cnt,ans);
            
            for (auto it: words[i]){
                freq[it]--;
                temp-=score[it-'a'];
            }
        }
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int>cnt,freq;
        for (auto it:letters){
            cnt[it]++;
        }
        int ans = 0;
        solve(0,0,words,score,freq,cnt,ans);
        return ans;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<string>words(n);
    vector<char>letters(m);
    vector<int>score(26);
    
    for (int i=0;i<n;i++){
        cin>>words[i];
    }
    for (int i=0;i<m;i++){
        cin>>letters[i];
    }
    for (int i=0;i<26;i++){
        cin>>score[i];
    }
    
    Solution ob;
    auto ans = ob.maxScoreWords(words,letters,score);
    cout<<ans;
    return 0;
}