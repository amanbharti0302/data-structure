/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

*/

class Solution {
public:
    int timer = 1;
    int in[100005];
    int low[100005];
    
    vector<int>visited;
    vector<int>adj[100005];
    vector<vector<int>>res;
    
    
    void dfs(int src,int p =-1){
        in[src] = low[src] = timer++;
        visited[src] = true;
        
        for(auto to:adj[src]){
            if(to==p)continue;
            if(visited[to]){
                low[src] = min(low[src],in[to]);
                continue;
            }
            dfs(to,src);
            low[src] = min(low[src],low[to]);
            if(in[src]<low[to]){res.push_back({to,src});}
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto x: connections){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        visited.assign(n+1,false);
        dfs(0);
        return res;
    }
};