/*
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

class Solution {
public:
    
    vector<pair<int,int>>adj[102];
        
    int dij(int k,int n){
        vector<int>dis(n+1,100000000);
        set<pair<int,int>>s;
        dis[k] = 0;
        s.insert({0,k});

        
        while(s.size()>0){
            int tm = (*s.begin()).first;
            int curr = (*s.begin()).second;
            s.erase(s.begin());
            
            for(auto to : adj[curr]){
                if(dis[curr]+to.second<dis[to.first]){
                    s.erase({dis[to.first],to.first});
                    dis[to.first] = dis[curr]+to.second;
                    s.insert({dis[curr]+to.second,to.first});
                }
            }
            
            
        }
        
        
        int ans = 0;
        for(int i =1;i<=n;i++){
            if(dis[i]>=100000000)return -1;
            ans = max(ans,dis[i]);
        }
        
        return ans;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto to:times){
            adj[to[0]].push_back({to[1],to[2]});
        }
        
        return dij(k,n);
    }
};