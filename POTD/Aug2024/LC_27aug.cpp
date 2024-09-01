//  Path with Maximum Probability (Medium)

// You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
// Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
// If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

// Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
// Output: 0.25000
// Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0);
        dist[start_node] = 1.0;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto it = pq.top();
            double prob = it.first;
            int node = it.second;
            pq.pop();
            if (node == end_node){
                return prob;
            }
            for(auto j:adj[node]){
                int adjNode = j.first;
                double wt = j.second;
                if ( dist[adjNode] < prob*wt){
                    dist[adjNode] = prob*wt;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        return 0;
    }
};
signed main()
{    
    int n;
    cin>>n;
    vector<vector<int>>edges(n,vector<int>(2));
    for (int i=0;i<n;i++){
        for (int j=0;j<2;j++){
            cin>>edges[i][j];
        }
    }
    vector<double>succProb(n);
    for(int i=0;i<n;i++){
        cin>>succProb[i];
    }
    int start_node,end_node;
    cin >> start_node >> end_node;
    Solution ob;
    auto ans = ob.maxProbability(n,edges,succProb,start_node,end_node);
    cout<<ans;
    return 0;
}