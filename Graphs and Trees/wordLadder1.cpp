// Finding the count of word transformations

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

int bfs(string start,string end,vector<string>& words){
  
  // Creating Queue DS to store word and count
  queue<pair<string,int>>q;
  
  // BFS Traversal by pushing words in q
  q.push({start,1});
  
  //Store list 'Words' into a set
  unordered_set<string>st(words.begin(),words.end());
  st.erase(start);
  
  while(!q.empty()){
    string word = q.front().first;
    int cnt = q.front().second;
    q.pop();
    
    // Base Case
    if (word == end){
      return cnt;
    }
    
    for (int i=0;i<word.size();i++){
      char original = word[i];
      // Now traverse across 'a' to 'z' and check which character is present in word
      for (char ch = 'a';ch<='z';ch++){
        word[i] = ch;
        if (st.find(word)!=st.end()){
          st.erase(word);
          q.push({word,cnt+1});
        }
      }
      word[i] = original;
    }
  }
  return 0;
}  
signed main()
{  
  string start,end;
  cin>>start>>end;
  vector<string>words(5);
  for (int i=0;i<5;i++){
    cin>>words[i];
  }
  cout<<bfs(start,end,words);
  return 0;
}