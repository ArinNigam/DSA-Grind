// Finding the number of word transformations

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
const int N=1e5+5;
vector<int>nums[N];

vector<vector<string>> func(string start,string end,vector<string> words){
  vector<vector<string>>ans;
  vector<string>temp;
  
  // Store the word in queue DS
  queue<vector<string>>q;
  
  // Replace words list with set to remove words easily
  unordered_set<string>st(words.begin(), words.end());
  
  
  q.push({start});
  temp.push_back(start);
  int lvl = 0;
  
  while(!q.empty()){
    vector<string> vec = q.front();
    q.pop();
    
    // Erase all words that are used in previous lvls 
    if (vec.size()>lvl){
      lvl++;
      for (auto it : temp){
        st.erase(it);
      }
    }
    
    string word = vec.back();
    
    if (word == end){
      if (ans.size()==0){
        ans.push_back(vec);
      }
      else if (ans[0].size()==vec.size()){
        ans.push_back(vec);
      }
    }
    
    for (int i=0;i<word.size();i++){
      char original = word[i];
      for (char ch= 'a'; ch<='z';ch++){
        word[i]= ch;
        if (st.count(word)>0){
          vec.push_back(word);
          q.push(vec);
          temp.push_back(word);
          vec.pop_back();
        }
      }
      word[i] = original;
    } 
  }
  return ans;
}  
bool compare(vector<string>a,vector<string>b){
  string x="",y="";
  for (string i: a){
    x+=i;
  }
  for (string i: b){
    y+=i;
  }
  return x<y;
}

signed main()
{  
  string start,end;
  cin>>start>>end;
  int n = 6;
  vector<string>words(n);
  for (int i=0;i<n;i++){
    cin>>words[i];
  }
  
  auto ans = func(start,end,words);
  
  if (ans.size()==0){
    return -1;
  }
  else{
    sort(ans.begin(),ans.end(),compare);
    for (auto i: ans){
      for (auto j: i){
        cout<<j<<" ";
      }
      cout<<endl;
    }
  }
  
  return 0;
}