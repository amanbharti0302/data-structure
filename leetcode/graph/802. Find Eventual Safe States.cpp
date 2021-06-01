/*
We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node (that is, it has no outgoing directed edges), we stop.

We define a starting node to be safe if we must eventually walk to a terminal node. More specifically, there is a natural number k, so that we must have stopped at a terminal node in less than k steps for any choice of where to walk.

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

The directed graph has n nodes with labels from 0 to n - 1, where n is the length of graph. The graph is given in the following form: graph[i] is a list of labels j such that (i, j) is a directed edge of the graph, going from node i to node j.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]

*/

class Solution {
public:
    vector<int>ans;
    vector<int>safe;
    
    bool dfs(int src,vector<vector<int>>& g){
        if(safe[src]!=-1)return safe[src];
        
        bool ans = true;
        safe[src] = 0;
        
        for(auto to:g[src]){
            ans = ans&dfs(to,g);
        }
        
        return safe[src]  = ans;
    }
    
    
    vector<int> eventualSafeNodes(vector<vector<int>>& g) {       
        safe.assign(g.size()+5,-1);
        
        for(int i= 0;i<g.size();i++){
           if(dfs(i,g)==1)ans.push_back(i);            
        }
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};