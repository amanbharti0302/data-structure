/*There is an undirected weighted connected graph. You are given a positive integer n which denotes that the graph has n nodes labeled from 1 to n, and an array edges where each edges[i] = [ui, vi, weighti] denotes that there is an edge between nodes ui and vi with weight equal to weighti.

A path from node start to node end is a sequence of nodes [z0, z1, z2, ..., zk] such that z0 = start and zk = end and there is an edge between zi and zi+1 where 0 <= i <= k-1.

The distance of a path is the sum of the weights on the edges of the path. Let distanceToLastNode(x) denote the shortest distance of a path between node n and node x. A restricted path is a path that also satisfies that distanceToLastNode(zi) > distanceToLastNode(zi+1) where 0 <= i <= k-1.

Return the number of restricted paths from node 1 to node n. Since that number may be too large, return it modulo 109 + 7.
Example 1:


Input: n = 5, edges = [[1,2,3],[1,3,3],[2,3,1],[1,4,2],[5,2,2],[3,5,1],[5,4,10]]
Output: 3
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The three restricted paths are:
1) 1 --> 2 --> 5
2) 1 --> 2 --> 3 --> 5
3) 1 --> 3 --> 5
Example 2:


Input: n = 7, edges = [[1,3,1],[4,1,2],[7,3,4],[2,5,3],[5,6,1],[6,7,2],[7,5,3],[2,6,4]]
Output: 1
Explanation: Each circle contains the node number in black and its distanceToLastNode value in blue. The only restricted path is 1 --> 3 --> 7.

====>  APPROACH

It can be solved using dunamic programming and dijikstra's algotithm.
first we find sortest path from n to all node using dijikstra. this is distanceto(x) for every node.
now we can run dfs from 1 to reach to n such that we will child from src in way that child distanceto(x)< distanceto(src)
to overcome with overlaping cases we will go with dp.
*/



using p = pair<int,int>;
static int mod = 1000000007;

class Solution {
public:
   static int dfs(int src,int &n,vector<int>&dis,vector<int>&dp,vector<vector<p>>&adj){
        if(src>n)return 0;
        if(src==n){return 1;}
        if(dp[src]!=-1)return dp[src];
        int ans = 0;
        
        for(auto to:adj[src]){
            auto to_node = to.first;
            if(to_node==src)continue;
            if(dis[to_node]<dis[src]){
                ans += dfs(to_node,n,dis,dp,adj);
                ans = ans%mod;
            }
        }
        
        return dp[src] = ans;
    }
    
    
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<p>>adj(n+1);
        
        for(int x = 0;x<(int)edges.size();x++){
            adj[edges[x][0]].push_back({edges[x][1],edges[x][2]});
            adj[edges[x][1]].push_back({edges[x][0],edges[x][2]});
        }
        
        vector<int>dis(n+1,INT_MAX);
        
        priority_queue<p,vector<p>,greater<>>pq;
        pq.push({0,n});
        dis[n] = 0;
        
        while(!pq.empty()){
            int cur_dist = (pq.top()).first;
            int cur_node = (pq.top()).second;
            pq.pop();
            
            for(auto to:adj[cur_node]){
                int to_node = to.first;
                int to_dist = to.second;
                
                if(dis[to_node]==INT32_MAX||dis[to_node]>cur_dist+to_dist){
                    pq.push({cur_dist+to_dist,to_node});
                    dis[to_node] = cur_dist+to_dist;
                }
            }
        }
        
        vector<int>dp(n+1,-1);
        return dfs(1,n,dis,dp,adj);
    }
};