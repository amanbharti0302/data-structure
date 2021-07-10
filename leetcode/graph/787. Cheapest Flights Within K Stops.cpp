/*
There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.
You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture
*/

class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto x:flights)
        adj[x[0]].push_back({x[1],x[2]});
        
        using v = vector<int>;
        
        vector<int>ans(n+1,INT_MAX);
        
        priority_queue<v, vector<v> ,greater<> > pq;
        pq.push({0,src,0});
        
        while(!pq.empty()){
            auto cur_amt = pq.top()[0];
            auto cur_nod = pq.top()[1];
            auto cur_stop = pq.top()[2];
            pq.pop();
            
            if(cur_nod==dst){return cur_amt;}
            if(cur_stop>k)continue;
            
            ans[cur_nod] = cur_stop;
            
            for(auto to:adj[cur_nod]){
                int to_nod = to.first;
                int to_pr = to.second;
                
                if(ans[to_nod]>cur_stop){
                    pq.push({cur_amt+to_pr,to_nod,cur_stop+1});
                }
            }
            
        }
        
        return -1;
    }
    
};