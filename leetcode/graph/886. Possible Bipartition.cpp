/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.
Example 1:

Input: N = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
Example 2:

Input: N = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
Example 3:

Input: N = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
*/

class Solution {
public:
    vector<int>visited;
    vector<int>col;
    
    bool dfs(int src,int c,vector<vector<int>>& dislikes){
        visited[src] = true;
        col[src] = c;
                
        for(auto to :dislikes[src]){
            if(visited[to]){
                if(col[to]==c)return false;
                continue;
            }
            if(dfs(to,!c,dislikes)==false)return false;
        }
        
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        visited.assign(N+2,false);
        col.assign(N+1,0);
        
        vector<vector<int>>adj(N+1);
        
        for(auto to :dislikes){
            adj[to[0]].push_back(to[1]);
            adj[to[1]].push_back(to[0]);
        }
        
        bool ans = true;
        for(int i = 0;i<N;i++)
            if(!visited[i])ans = ans& dfs(i,0,adj);
        return ans;
    }
};