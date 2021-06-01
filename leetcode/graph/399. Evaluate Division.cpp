/*
You are given an array of variable pairs equations and an array of real numbers values, where equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.

You are also given some queries, where queries[j] = [Cj, Dj] represents the jth query where you must find the answer for Cj / Dj = ?.

Return the answers to all queries. If a single answer cannot be determined, return -1.0.

Note: The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

 

Example 1:

Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
*/


map<string,vector<pair<string,double>>>adj;
set<string>visited;
double ans = 0;

double dfs(pair<string,double> src,string end,string p){
    visited.insert(src.first);
    if(src.first==end)return src.second;
    
    for(auto to :adj[src.first]){
        if(to.first==p)continue;
        if(visited.count(to.first)>0)return -1;
        double temp = dfs(to,end,src.first);
        if(temp!=-1)return src.second*temp;
    }
    
    return -1;
    
}

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& vl, vector<vector<string>>& qr) {
        adj.clear();
        
        for(int i=0;i<eq.size();i++){
            adj[eq[i][0]].push_back({eq[i][1],vl[i]});
            adj[eq[i][1]].push_back({eq[i][0],1/vl[i]});
        }
        
        vector<double>sol;
        
        for(int i=0;i<qr.size();i++){
            visited.clear();
            string src = qr[i][0],to= qr[i][1];
            if(adj[src].size()==0||adj[to].size()==0)sol.push_back(-1);
            else if(src==to)sol.push_back(1);
            else sol.push_back(dfs({src,1},to,""));
        }
        
        return sol;
    }
};