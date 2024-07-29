// Second Minimum Time to Reach Destination (Hard)

// A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.
// Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.
// The second minimum value is defined as the smallest value strictly larger than the minimum value.
// For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.
// Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

// Notes
// You can go through any vertex any number of times, including 1 and n.
// You can assume that when the journey starts, all signals have just turned green.
 
// Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
// Output: 13
// Explanation:
// The figure on the left shows the given graph.
// The blue path in the figure on the right is the minimum time path.
// The time taken is:
// - Start at 1, time elapsed=0
// - 1 -> 4: 3 minutes, time elapsed=3
// - 4 -> 5: 3 minutes, time elapsed=6
// Hence the minimum time needed is 6 minutes.

// The red path shows the path to get the second minimum time.
// - Start at 1, time elapsed=0
// - 1 -> 3: 3 minutes, time elapsed=3
// - 3 -> 4: 3 minutes, time elapsed=6
// - Wait at 4 for 4 minutes, time elapsed=10
// - 4 -> 5: 3 minutes, time elapsed=13
// Hence the second minimum time is 13 minutes.     

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    #define pii pair<int,int>
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
        vector<int> dist1(n,INT_MAX),dist2(n,INT_MAX),freq(n);
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        dist1[0] = 0;
        pq.push({0,0});
        
        while(!pq.empty()){
            auto it = pq.top();
            int timeTaken = it.first;
            int node = it.second;
            pq.pop();
            freq[node]++;
            if (freq[node] == 2 && node == n-1){
                return timeTaken;
            }
            if ((timeTaken/change)%2){
                timeTaken = (timeTaken/change + 1) * change + time;
            }
            else{
                timeTaken += time;
            }
          
            for(auto adjNode:adj[node]){
                if (freq[adjNode] == 2) continue;
                if (dist1[adjNode] > timeTaken){
                    dist1[adjNode] = timeTaken;
                    pq.push({timeTaken,adjNode});
                }
                else if(dist2[adjNode] > timeTaken && dist1[adjNode] != timeTaken){
                    dist2[adjNode] = timeTaken;
                    pq.push({timeTaken,adjNode});
                }
            } 
        }
        return 0;
    }
};

signed main()
{    
    int n,m;
    cin>>n>>m;
    vector<vector<int>>edges(m,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    int time;
    cin>>time;
    int change;
    cin>>change;
    Solution ob;
    auto ans = ob.secondMinimum(n,edges,time,change);
    cout<<ans;
    return 0;
}