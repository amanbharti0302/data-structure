/*
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.2], start = 0, end = 2
Output: 0.25000
Explanation: There are two paths from start to end, one having a probability of success = 0.2 and the other has 0.5 * 0.5 = 0.25.

Example 2:
Input: n = 3, edges = [[0,1],[1,2],[0,2]], succProb = [0.5,0.5,0.3], start = 0, end = 2
Output: 0.30000

Example 3:
Input: n = 3, edges = [[0,1]], succProb = [0.5], start = 0, end = 2
Output: 0.00000
Explanation: There is no path between 0 and 2.

*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        double ans = 0.0;
        using p = pair<double,int>;
        
        vector<vector<pair <double,double> >>adj(n+2);
        
        for(int i = 0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        vector<double>dis(n+1,0.0);
        priority_queue<p>pq;
        pq.push({1.0,start});
        dis[start] = 1.0;
        
        while(!pq.empty()){
            auto curr_pr = pq.top().first;
            auto curr_node = pq.top().second;
            
            pq.pop();
            
            for(auto to:adj[curr_node]){
                if(dis[to.first]>=curr_pr*to.second)continue;
                dis[to.first] = curr_pr*to.second;
                pq.push({dis[to.first],to.first});
            }
        }
        
        return dis[end];
    }
    
};