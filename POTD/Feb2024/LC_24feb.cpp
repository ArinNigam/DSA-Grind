#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define pii pair<int,int>
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pii>>adj(n);
        for (auto it:meetings){
            auto x = it[0],y = it[1],t = it[2];
            adj[x].push_back(make_pair(t,y));
            adj[y].push_back(make_pair(t,x));
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        vector<int>secret(n,INT_MAX);
        vector<int> ans;
        
        pq.push(make_pair(0,0));
        pq.push(make_pair(0,firstPerson));
        
        while(!pq.empty()){
            
            auto it = pq.top();
            pq.pop();
            
            auto time = it.first;
            auto person = it.second;
            
            if (secret[person]!=INT_MAX) continue;
            
            ans.push_back(person);
            secret[person] = time;
            for (auto it: adj[person]){
                int t = it.first;
                int p = it.second;
                
                if (secret[p]!=INT_MAX || t<time) continue;
                
                pq.push(make_pair(t,p));
            }
        }
        
        return ans;
    }
};

signed main()
{    
    int m,n;
    cin>>m>>n;
    vector<vector<int>>nums(n,vector<int>(3));
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin>>nums[i][j];
        }
    }
    int firstPerson;
    cin>>firstPerson;
    Solution ob;
    auto ans = ob.findAllPeople(m,nums,firstPerson);
    for (auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}