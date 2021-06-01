/*
In this problem, a tree is an undirected graph that is connected and has no cycles.
You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

Example 1:


Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
Example 2:
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]

*/

class Solution {
public:
    vector<int>g[1001];
    map<pair<int,int>,int>sol;
    int timer=0;
    int in[1001];
    int low[1001];
    
    
    void dfs(int src,int p,vector<bool>& visited){
        visited[src]=true;
        in[src]=low[src] = timer++;
        
        for(auto to:g[src]){
            if(to==p)continue;
            if(visited[to]){
                low[src] = min(low[src],in[to]);
            }
            else {
                dfs(to,src,visited);
                low[src] = min(low[src],low[to]);
                if(low[to]>in[src]){
                    sol[make_pair(src,to)]++;
                }
            };
        }
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& ed) {
        
        vector<bool>visited(ed.size()+1,false);       
        for(auto x:ed){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        
        dfs(1,-1,visited);
        
        for(int i=ed.size()-1;i>=0;i--){
            if(sol.find({ed[i][0],ed[i][1]})==sol.end()&&sol.find({ed[i][1],ed[i][0]})==sol.end())return {ed[i][0],ed[i][1]};
         }
        
        return {1,1};
    }
};