// Task Scheduler (Medium)
// You are given an array of CPU tasks, each represented by letters A to Z, and a cooling time, n. Each cycle or interval allows the completion of one task. Tasks can be completed in any order, but there's a constraint: identical tasks must be separated by at least n intervals due to cooling time n.
// Return the minimum number of intervals required to complete all tasks.

// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
// After completing task A, you must wait two cycles before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th cycle, you can do A again as 2 intervals have passed.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int>pq;
        vector<int>mp(26,0);
        for (auto it:tasks){
            mp[it-'A']++;
        }
        for(int i=0;i<26;i++){
            if (mp[i]!=0){
                pq.push(mp[i]);
            }
        }
        int time = 0;
        while(!pq.empty()){
            vector<int>left;
            int cycle=n+1;
            while(cycle && !pq.empty()){
                int maxi = pq.top();
                pq.pop();
                if (maxi > 1){
                    left.push_back(maxi-1);
                }
                ++time;
                --cycle;
            }
            for(auto it:left){
                pq.push(it);
            }
            
            if (pq.empty()) break;
            time+=cycle;
        }
        return time;
    }
};

signed main()
{    
    int n;
    cin>>n;
    vector<char>tasks(n);
    for (int i=0;i<n;i++){
        cin>>tasks[i];
    }
    Solution ob;
    auto ans = ob.leastInterval(tasks,n);
    cout<<ans;
    return 0;
}